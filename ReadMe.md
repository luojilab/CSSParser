# DDCSSParser - A C++ CSS Parser

DDCSSParser是一个C++实现的css解析器。最终会生成一系列的selector的模型（Selector类），并且会依据一个Selector判断CSS是否适用于某一个HTML的DOM节点。

## Installation

* 将代码拷贝至本地`git clone xxxx`
* 提取出来**Src**文件夹中的内容到工程中

## Feature

#### 支持的CSS Selector：

* Simple Selector:
  * Type Selector
  * Universal Selector
  * Attribute Selector
  * Class Selector
  * ID Selector
* Combinators:
  * Descendant combinator
  * Child combinators
  * Sibling combinators

#### 不支持的CSS Selector：

* 伪类（pseudo class）

#### 将要实现的目标：

* 移除对于[Gumbo](https://github.com/google/gumbo-parser)的依赖
* 增加对于伪类的支持
* 增加对于CSS规则的建模
* 消除可能存在的一些bug

## Basic Usage

```c++
#include "gumbo.h"
#include "CSSParser.hpp"
#include "GumboInterface.h"
#include "HTMLCSSRefAdaptor.h"

// 建立CSS Selector的模型
future::GumboInterface gi(ptr, "2");
future::CSSParser* parser = new future::CSSParser;
parser->parse("/Path/to/CssFile");
std::list<future::Selector *>selectors = parser>getSelectors();

// 查询CSS某一条规则是否应用到HTML的某一节点上
future::Selector* selector = *selectors.begin();
GumboNode *root = gi.get_root_node();
future::HTMLCSSRefAdaptor::GumboArray nodesArray = &root;
future::HTMLCSSRefAdaptor::nodeAdaptToSelector(&nodesArray, selector);
```

## Dependency

* [Google Gumbo](https://github.com/google/gumbo-parser)
* [Sigil](https://github.com/Sigil-Ebook/Sigil) Gumbo Interface

