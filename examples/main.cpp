//
//  main.cpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/1.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#include <iostream>
#include "CSSParser.hpp"
#include "KeywordItem.hpp"
#include "gumbo.h"
#include "GumboInterface.h"
#include "HTMLCSSRefAdaptor.h"

void Applicability(GumboNode *root, future::Selector* selector);
void AllNodesApplyToSelector(GumboNode *root, future::Selector* selector, std::list<GumboNode *>&list);

int main(int argc, const char * argv[]) {
    const char* htmlPath = "/Path/To/HTMLFile";
    const char* cssPath = "/Path/To/CSSFile";
    FILE *f = fopen(htmlPath, "r");
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* ptr = new char[size];
    fread((void *)ptr, size, 1, f);
    fclose(f);
    
    future::GumboInterface gi(ptr, "2");
    future::CSSParser* parser = new future::CSSParser;
    parser->parseByFile(cssPath);
    std::list<future::Selector *>selectors = parser->getSelectors();
    // Demo1:
    // 检测html中的node，是否适用于一个css的selector
    // Check whether a css selector can apply to a html node
    for (future::Selector *s : selectors) {
        // Tranvers DOM tree
        Applicability(gi.get_root_node(), s);
    }
    // Demo2:
    // 找到所有适用于某一selector的DMO节点
    // checkout All Nodes in DOM that can apply to a specific selector
    std::list<GumboNode*>allNodes;
    std::list<GumboNode*>&allNodesRef = allNodes;
    future::Selector* s = *selectors.begin();
    AllNodesApplyToSelector(gi.get_root_node(), s, allNodesRef);
    delete [] ptr;
    delete parser;
    return 0;
}

void Applicability(GumboNode *root, future::Selector* selector)
{
    if (root->type == GUMBO_NODE_ELEMENT) {
        GumboVector children = root->v.element.children;
        for (unsigned int i = 0; i < children.length; i++) {
            GumboNode*child = (GumboNode *)(children.data[i]);
            Applicability(child, selector);
        }
        const char* name = HTMLTagNames[root->v.element.tag];
        future::HTMLCSSRefAdaptor::GumboArray nodesArray = &root;
        printf("%s match selector %d line: %d\n",
               name,
               future::HTMLCSSRefAdaptor::nodeAdaptToSelector(&nodesArray, selector),
               root->v.element.start_pos.line);
    }
    future::HTMLCSSRefAdaptor::CleanResource();
}

void AllNodesApplyToSelector(GumboNode *root, future::Selector* selector, std::list<GumboNode *>&list)
{
    if (root->type == GUMBO_NODE_ELEMENT) {
        GumboVector children = root->v.element.children;
        for (unsigned int i = 0; i < children.length; i++) {
            GumboNode*child = (GumboNode *)(children.data[i]);
            AllNodesApplyToSelector(child, selector, list);
        }
        future::HTMLCSSRefAdaptor::GumboArray nodesArray = &root;
        if (future::HTMLCSSRefAdaptor::nodeAdaptToSelector(&nodesArray, selector)) {
            list.push_back(root);
        }
    }
    future::HTMLCSSRefAdaptor::CleanResource();
}
