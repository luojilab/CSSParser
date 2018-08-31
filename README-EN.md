# DDCSSParser - A C++ CSS Parser

[中文文档](./README.md)

DDCSSParser is a CSS parser implemented by c++. By this parser, user can get a series of CSS model and check whether a CSS model (a CSS rule) can be applied to an HTML DOM node.

## Installation

* Copy source code in working directory `git clone https://github.com/luojilab/CSSParser.git`
* Extract the source code in **Src** directory into working project

## Feature

#### Supported CSS Selector:

- Simple Selector:
  - Type Selector
  - Universal Selector
  - Attribute Selector
  - Class Selector
  - ID Selector
- Selector Sequence
- Selector Group
- Combinators:
  - Descendant combinator
  - Child combinators
  - Sibling combinators

#### Unsupported CSS Selector:

* Pseudo Class

## Goals to Achive

* Remove dependency to [Gumbo](https://github.com/google/gumbo-parser)
* Support parsing pseudo
* Support modeling for CSS rule
* Remove some potential bugs

## Basic Usage

```c++
#include "gumbo.h"
#include "CSSParser.hpp"
#include "GumboInterface.h"
#include "HTMLCSSRefAdaptor.h"

// modeling for css selector
future::GumboInterface gi(ptr, "2");
future::CSSParser* parser = new future::CSSParser;
parser->parse("/Path/to/CssFile");
std::list<future::Selector *>selectors = parser>getSelectors();

// check whether a css selector can be applied to HTML DOM node
future::Selector* selector = *selectors.begin();
GumboNode *root = gi.get_root_node();
future::HTMLCSSRefAdaptor::GumboArray nodesArray = &root;
future::HTMLCSSRefAdaptor::nodeAdaptToSelector(&nodesArray, selector);
```

## Dependency

* [Google Gumbo](https://github.com/google/gumbo-parser)