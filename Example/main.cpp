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

void tranversTree(GumboNode *root, future::Selector* selector)
{
    if (root->type == GUMBO_NODE_ELEMENT) {
        GumboVector children = root->v.element.children;
        for (unsigned int i = 0; i < children.length; i++) {
            GumboNode*child = (GumboNode *)(children.data[i]);
            tranversTree(child, selector);
        }
        const char* name = HTMLTagNames[root->v.element.tag];
        future::HTMLCSSRefAdaptor::GumboArray nodesArray = &root;
        printf("%s match selector %d line: %d\n", name, future::HTMLCSSRefAdaptor::nodeAdaptToSelector(&nodesArray, selector), root->v.element.start_pos.line);
    }
    future::HTMLCSSRefAdaptor::CleanResource();
}

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
    parser->parse(cssPath);
    std::list<future::Selector *>selectors = parser->getSelectors();
    delete parser;
    for (future::Selector *s : selectors) {
        tranversTree(gi.get_root_node(), s);
        printf("\n");
    }
    delete [] ptr;
    return 0;
}
