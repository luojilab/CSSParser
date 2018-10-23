# DDCSSParser - A C++ CSS Parser

[![LISCENSE](https://img.shields.io/packagist/l/doctrine/orm.svg)](./LICENSE)

[中文文档](./README.md)

------

DDCSSParser is a CSS parser implemented by c++. By this parser, user can get a series of CSS model and check whether a CSS model (a CSS rule) can be applied to an HTML DOM node.

## Installation

##### Using Code

* Copy source code in working directory `git clone https://github.com/luojilab/CSSParser.git`
* Extract the source code in **Src** directory into working project

##### Running Demo

- `./autogen.sh`
- `./configure`
- `make`
- `./example`

## Feature

#### Supported CSS Selector:

- Simple Selector:
  - Type Selector
  - Universal Selector
  - Attribute Selector
  - Class Selector
  - ID Selector
  - Pseudo Class
- Selector Sequence
- Selector Group
- Combinators:
  - Descendant combinator
  - Child combinators
  - Sibling combinators

## Goals to Achive

* Remove dependency to [Gumbo](https://github.com/google/gumbo-parser)
* Support modeling for CSS rule
* Remove some potential bugs

## Basic Usage

* Modling CSS Selector

  ```c++
  // parse css file
  future::CSSParser* parser = new future::CSSParser;
  parser->parseByFile("/Path/to/CssFile");
  std::list<future::Selector *>selectors = parser>getSelectors();
  // parse css string
  parser->parseByString("body #id {}");
  std::list<future::Selector *>selectors = parser>getSelectors();
  ```

* Check whether a CSS selector can be applied to an HTML DOM node

  ```c++
  // selectors is all selector model parsed by a css file
  future::Selector* selector = *selectors.begin();
  // get a DOM node (root node in this example)
  GumboNode *root = gi.get_root_node();
  // initial argument
  future::HTMLCSSRefAdaptor::GumboArray nodesArray = &root;
  // check whether a CSS selector can be applied to an HTML DOM node
  future::HTMLCSSRefAdaptor::nodeAdaptToSelector(&nodesArray, selector);
  ```

* Find out all the HTML DOM nodes that can use a specific CSS node

  ```c++
  // tranverse DOM tree
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
  // Find out all the HTML DOM nodes that can use a specific CSS node
  std::list<GumboNode*>&allNodesRef = allNodes;
  future::Selector* s = *selectors.begin();
  AllNodesApplyToSelector(gi.get_root_node(), s, allNodesRef);
  ```

## Applicability

The code has been test on iOS/Android/Linux/Windows

Using on Android, you must write a seperator API for Java

## Dependency

* [Google Gumbo](https://github.com/google/gumbo-parser)