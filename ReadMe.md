# DDCSSParser - A C++ CSS Parser

[![LISCENSE](https://img.shields.io/packagist/l/doctrine/orm.svg)](./LICENSE.md)

[English document](./README-EN.md)

------

DDCSSParser是一个C++实现的css解析器。最终会生成一系列的selector的模型（Selector类），并且会依据一个Selector判断CSS是否适用于某一个HTML的DOM节点。

## 安装

##### 使用代码

* 将代码拷贝至本地`git clone https://github.com/luojilab/CSSParser.git`
* 提取出来**Src**文件夹中的内容到工程中

##### 运行demo

* `./autogen.sh`
* `./configure`
* `make`
* `./example`

## 特性

#### 支持的CSS Selector：

* Simple Selector:
  * Type Selector
  * Universal Selector
  * Attribute Selector
  * Class Selector
  * ID Selector
  * Pseudo Class
* Selector Sequence
* Selector Group
* Combinators:
  * Descendant combinator
  * Child combinators
  * Sibling combinators

#### 将要实现的目标：

* 移除对于[Gumbo](https://github.com/google/gumbo-parser)的依赖
* 增加对于CSS规则的建模
* 消除可能存在的一些bug

## 基础用法

* 建立CSS Selector的模型

  ```c++
  // 解析css文件
  future::CSSParser* parser = new future::CSSParser;
  parser->parseByFile("/Path/to/CssFile");
  std::list<future::Selector *>selectors = parser>getSelectors();
  // 解析css字符串
  parser->parseByString("body #id {}");
  std::list<future::Selector *>selectors = parser>getSelectors();
  ```

* 查询CSS某一条规则是否应用到HTML的某一节点上

  ```c++
  // selectors为解析出来的所有selector的选择器模型
  future::Selector* selector = *selectors.begin();
  // 获取某一个节点（本例是根结点）
  GumboNode *root = gi.get_root_node();
  // 初始化数据
  future::HTMLCSSRefAdaptor::GumboArray nodesArray = &root;
  // 查询selector这个css选择是否可以应用到root这个DOM节点中
  future::HTMLCSSRefAdaptor::nodeAdaptToSelector(&nodesArray, selector);
  ```

* 查询满足某一个Selector的所有DOM节点

  ```c++
  // 遍历DOM树
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
  // 查找所有满足选择器s的所有DOM节点
  std::list<GumboNode*>&allNodesRef = allNodes;
  future::Selector* s = *selectors.begin();
  AllNodesApplyToSelector(gi.get_root_node(), s, allNodesRef);
  ```

## 适用性

本代码经过测试已经在iOS/Android/Linux/windows上测试通过。

*Android需要单独写接口对接Java*


## 依赖

* [Google Gumbo](https://github.com/google/gumbo-parser)

