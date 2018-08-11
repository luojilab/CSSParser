/*
 * HTMLCSSRefAdaptor.cpp
 *
 *  Created on: 2018-8-9
 *      Author: 1m0nster
 */

#include "HTMLCSSRefAdaptor.h"
#include "StringUtil.h"

extern const int HTMLTAGMAXSIZE = 257;
const char* HTMLTagNames[] = {
    "A", "ABBR", "ACRONYM", "ADDRESS", "ALTGLYPH", "ALTGLYPHDEF", "ALTGLYPHITEM",
    "ANIMATE",
    "ANIMATECOLOR",
    "ANIMATEMOTION",
    "ANIMATETRANSFORM",
    "ANNOTATION_XML",
    "APPLET",
    "AREA",
    "ARTICLE",
    "ASIDE",
    "AUDIO",
    "B",
    "BASE",
    "BASEFONT",
    "BDI",
    "BDO",
    "BGSOUND",
    "BIG",
    "BLINK",
    "BLOCKQUOTE",
    "BODY",
    "BR",
    "BUTTON",
    "CANVAS",
    "CAPTION",
    "CENTER",
    "CIRCLE",
    "CITE",
    "CLIPPATH",
    "CODE",
    "COL",
    "COLGROUP",
    "COLOR_PROFILE",
    "CURSOR",
    "DATA",
    "DATALIST",
    "DD",
    "DEFS",
    "DEL",
    "DESC",
    "DETAILS",
    "DFN",
    "DIR",
    "DIV",
    "DL",
    "DT",
    "ELLIPSE",
    "EM",
    "EMBED",
    "FEBLEND",
    "FECOLORMATRIX",
    "FECOMPONENTTRANSFER",
    "FECOMPOSITE",
    "FECONVOLVEMATRIX",
    "FEDIFFUSELIGHTING",
    "FEDISPLACEMENTMAP",
    "FEDISTANTLIGHT",
    "FEFLOOD",
    "FEFUNCA",
    "FEFUNCB",
    "FEFUNCG",
    "FEFUNCR",
    "FEGAUSSIANBLUR",
    "FEIMAGE",
    "FEMERGE",
    "FEMERGENODE",
    "FEMORPHOLOGY",
    "FEOFFSET",
    "FEPOINTLIGHT",
    "FESPECTACTUALRLIGHTING",
    "FESPOTLIGHT",
    "FETILE",
    "FETURBULENCE",
    "FIELDSET",
    "FIGCAPTION",
    "FIGURE",
    "FILTER",
    "FONT",
    "FONT_FACE",
    "FONT_FACE_FORMAT",
    "FONT_FACE_NAME",
    "FONT_FACE_SRC",
    "FONT_FACE_URI",
    "FOOTER",
    "FOREIGNOBJECT",
    "FORM",
    "FRAME",
    "FRAMESET",
    "G",
    "GLYPH",
    "GLYPHREF",
    "H1",
    "H2",
    "H3",
    "H4",
    "H5",
    "H6",
    "HEAD",
    "HEADER",
    "HGROUP",
    "HKERN",
    "HR",
    "HTML",
    "I",
    "IFRAME",
    "IMAGE",
    "IMG",
    "INPUT",
    "INS",
    "ISINDEX",
    "KBD",
    "KEYGEN",
    "LABEL",
    "LEGEND",
    "LI",
    "LINE",
    "LINEARGRADIENT",
    "LINK",
    "LISTING",
    "MACTION",
    "MAIN",
    "MALIGNGROUP",
    "MALIGNMARK",
    "MAP",
    "MARK",
    "MARKER",
    "MARQUEE",
    "MASK",
    "MATH",
    "MENCLOSE",
    "MENU",
    "MENUITEM",
    "MERROR",
    "META",
    "METADATA",
    "METER",
    "MFENCED",
    "MFRAC",
    "MGLYPH",
    "MI",
    "MISSING_GLYPH",
    "MLABELEDTR",
    "MLONGDIV",
    "MMULTISCRIPTS",
    "MN",
    "MO",
    "MOVER",
    "MPADDED",
    "MPATH",
    "MPHANTOM",
    "MPRESCRIPTS",
    "MROOT",
    "MROW",
    "MS",
    "MSCARRIES",
    "MSCARRY",
    "MSGROUP",
    "MSLINE",
    "MSPACE",
    "MSQRT",
    "MSROW",
    "MSTACK",
    "MSTYLE",
    "MSUB",
    "MSUBSUP",
    "MSUP",
    "MTABLE",
    "MTD",
    "MTEXT",
    "MTR",
    "MULTICOL",
    "MUNDER",
    "MUNDEROVER",
    "NAV",
    "NEXTID",
    "NOBR",
    "NOEMBED",
    "NOFRAMES",
    "NONE",
    "NOSCRIPT",
    "OBJECT",
    "OL",
    "OPTGROUP",
    "OPTION",
    "OUTPUT",
    "P",
    "PARAM",
    "PATH",
    "PATTERN",
    "PLAINTEXT",
    "POLYGON",
    "POLYLINE",
    "PRE",
    "PROGRESS",
    "Q",
    "RADIALGRADIENT",
    "RB",
    "RECT",
    "RP",
    "RT",
    "RTC",
    "RUBY",
    "S",
    "SAMP",
    "SCRIPT",
    "SECTION",
    "SELECT",
    "SEMANTICS",
    "SET",
    "SMALL",
    "SOURCE",
    "SPACER",
    "SPAN",
    "STOP",
    "STRIKE",
    "STRONG",
    "STYLE",
    "SUB",
    "SUMMARY",
    "SUP",
    "SVG",
    "SWITCH",
    "SYMBOL",
    "TABLE",
    "TBODY",
    "TD",
    "TEMPLATE",
    "TEXT",
    "TEXTPATH",
    "TEXTAREA",
    "TFOOT",
    "TH",
    "THEAD",
    "TIME",
    "TITLE",
    "TR",
    "TRACK",
    "TREF",
    "TSPAN",
    "TT",
    "U",
    "UL",
    "USE",
    "VAR",
    "VIDEO",
    "VIEW",
    "VKERN",
    "WBR",
    "XMP",
    "UNKNOWN",
    "LAST"
};
namespace future {
    
    static const char* CLASSATTRIBUTE = "class";
    static const char* IDATTRIBUTE = "id";
    HTMLCSSRefAdaptor::HTMLCSSRefAdaptor()
    {
    }
    
    HTMLCSSRefAdaptor::~HTMLCSSRefAdaptor()
    {
    }
    
    bool HTMLCSSRefAdaptor::nodeAdaptToSelector(GumboNode** node, Selector*selector,  int *potentialSize)
    {
        Selector::SelectorType type = selector->getType();
        switch(type) {
            case Selector::TypeSelector: {
                return nodeAdaptToTypeSelector(node, dynamic_cast<TypeSelector *>(selector));
            }
            case Selector::IDSelector: {
                return nodeAdaptToIDSelector(node, dynamic_cast<IdSelector *>(selector));
            }
            case Selector::ClassSelector: {
                return nodeAdaptToClassSelector(node, dynamic_cast<ClassSelector *>(selector));
            }
            case Selector::UniversalSelector: {
                return true;
            }
            case Selector::AttributeSelector: {
                return nodeAdaptToAttributeSelector(node, dynamic_cast<AttributeSelector *>(selector));
            }
            case Selector::PseudoSelector: {
                return nodeAdaptToPseudoSelector(node, dynamic_cast<PseudoSelector *>(selector));
            }
            case Selector::SimpleSelectorSequence: {
                return nodeAdaptToSequenceSelector(node, dynamic_cast<SequenceSelector *>(selector));
            }
            case Selector::CombineSelector: {
                return nodeAdaptToCombineSelector(node, dynamic_cast<CombineSelector *>(selector));
            }
            case Selector::SelectorGroup: {
                return nodeAdaptToGroupSelector(node, dynamic_cast<GroupSelector *>(selector));
            }
            default:
                return false;
        }
    }
    
    bool HTMLCSSRefAdaptor::nodeAdaptToClassSelector(GumboNode** nodePtr, ClassSelector* selector)
    {
        if ((*nodePtr)->type != GUMBO_NODE_ELEMENT) {
            return false;
        }
        std::string selectorClass = selector->getClassIdentifier();
        // A node may have multiClasses, so using substring relation
        AttributeSelector s(CLASSATTRIBUTE, selectorClass, AttributeSelector::Substring);
        return nodeAdaptToAttributeSelector(nodePtr, &s);
    }
    
    bool HTMLCSSRefAdaptor::nodeAdaptToIDSelector(GumboNode** nodePtr, IdSelector* selector)
    {
        if ((*nodePtr)->type != GUMBO_NODE_ELEMENT) {
            return false;
        }
        std::string selectorId = selector->getIdIdentifier();
        AttributeSelector s(IDATTRIBUTE, selectorId, AttributeSelector::Equal);
        return nodeAdaptToAttributeSelector(nodePtr, &s);
    }
    
    bool HTMLCSSRefAdaptor::nodeAdaptToTypeSelector(GumboNode** nodePtr, TypeSelector* selector)
    {
        GumboNode* node = *nodePtr;
        GumboTag tag;
        std::string tagName;
        if (node->type == GUMBO_NODE_ELEMENT) {
            tag = node->v.element.tag;
            if (tag >= HTMLTAGMAXSIZE) {
                return false;
            }
            tagName = HTMLTagNames[tag];
        } else if (node->type == GUMBO_NODE_DOCUMENT) {
            tagName = "html";
        } else {
            return false;
        }
        std::string selectorTagName = StringUtil::toupper(selector->getTagName());
        return selectorTagName == tagName;
    }
    
    bool HTMLCSSRefAdaptor::nodeAdaptToAttributeSelector(GumboNode** nodePtr, AttributeSelector* selector)
    {
        GumboNode* node = *nodePtr;
        if (node->type != GUMBO_NODE_ELEMENT) {
            return false;
        }
        std::string key = selector->getKey();
        std::string value = StringUtil::tolower(selector->getValue());
        AttributeSelector::attributeFilterRule kvRule = selector->getKVRule();
        GumboAttribute* attr = gumbo_get_attribute(&node->v.element.attributes, key.c_str());
        if (!attr) {
            return false;
        }
        std::string nodeAttrValue = StringUtil::tolower(attr->value);
        if (key.empty()) {
            return false;
        }
        bool ret = false;
        switch (kvRule) {
            case AttributeSelector::Equal: {
                ret = nodeAttrValue == value;
                break;
            }
            case AttributeSelector::DashMatch:
            case AttributeSelector::Prefix: {	// TODO tell the difference between include and substring
                ret = nodeAttrValue.rfind(value, 0) == 0;
                break;
            }
            case AttributeSelector::Suffix: {
                ret = nodeAttrValue.rfind(value) + value.length() == nodeAttrValue.length();
                break;
            }
            case AttributeSelector::Include:
            case AttributeSelector::Substring: {	// TODO tell the difference between include and substring
                ret = nodeAttrValue.find(value, 0) != std::string::npos;
                break;
            }
            case AttributeSelector::NoRule: {
                ret = true;
                break;
            }
            default:
                ret = false;
        }
        return ret;
    }
    
    bool HTMLCSSRefAdaptor::nodeAdaptToPseudoSelector(GumboNode** node, PseudoSelector* selector)
    {
        // TODO need finish
        return true;
    }
    
    bool HTMLCSSRefAdaptor::nodeAdaptToSequenceSelector(GumboNode **nodePtr, SequenceSelector* selector)
    {
        std::list<Selector *>ss = selector->getContrains();
        auto it = ss.begin();
        auto end = ss.end();
        bool ret = true;
        while(it != end) {
            ret = nodeAdaptToSelector(nodePtr, *it++) && ret;
            if (!ret) {
                return ret;
            }
        }
        return ret;
    }
    
    bool HTMLCSSRefAdaptor::nodeAdaptToGroupSelector(GumboNode** nodePtr, GroupSelector* selector)
    {
        std::list<Selector *>ss = selector->getAllSelectors();
        auto it = ss.begin();
        auto end = ss.end();
        bool ret = false;
        while(it != end) {
            ret = nodeAdaptToSelector(nodePtr, *it++) || ret;
        }
        return ret;
    }
    
    bool HTMLCSSRefAdaptor::nodeAdaptToCombineSelector(GumboNode** nodePtr, CombineSelector* selector)
    {
        GumboNode* node = *nodePtr;
        std::list<Selector *>selectors = selector->getNormalSiblingList();
        if (selectors.size() == 2) {
            Selector* before = *selectors.begin();
            Selector* after = *--selectors.end();
            bool afterMatch = false;
            bool beforeMatch = false;
            unsigned int c_idx = node->index_within_parent;
            GumboNode* parent = node->parent;
            if (!parent || parent->type != GUMBO_NODE_ELEMENT) {
                return false;
            }
            afterMatch = nodeAdaptToSelector(nodePtr, after);
            GumboVector children = parent->v.element.children;
            for (unsigned int i = 0; i < children.length; i++) {
                GumboNode* sibling = (GumboNode *)children.data[i];
                if (sibling->index_within_parent >= c_idx) {
                    continue;
                }
                beforeMatch = nodeAdaptToSelector(&sibling, before) || beforeMatch;
                if (beforeMatch) {
                    break;
                }
            }
            return beforeMatch && afterMatch;
        }
        selectors = selector->getInstanceSiblingList();
        if (selectors.size() == 2) {
            Selector* before = *selectors.begin();
            Selector* after = *--selectors.end();
            bool afterMatch = false;
            bool beforeMatch = false;
            GumboNode* parent = node->parent;
            if (!parent || parent->type != GUMBO_NODE_ELEMENT) {
                return false;
            }
            afterMatch = nodeAdaptToSelector(nodePtr, after);
            GumboVector children = parent->v.element.children;
            GumboNode* lastElementNode = 0;
            for (unsigned int i = 0; i < children.length; i++) {
                GumboNode* sibling = (GumboNode *)children.data[i];
                if (sibling == node && lastElementNode) {
                    beforeMatch = nodeAdaptToSelector(&lastElementNode, before) || beforeMatch;
                    break;
                }
                if (sibling->type == GUMBO_NODE_ELEMENT) {
                    lastElementNode = sibling;
                }
            }
            return beforeMatch && afterMatch;
        }
        selectors = selector->getInstanceInhericalList();
        if (selectors.size() == 2) {
            Selector* before = *selectors.begin();
            Selector* after = *--selectors.end();
            bool afterMatch = false;
            bool beforeMatch = false;
            GumboNode* parent = node->parent;
            if (!parent) {
                return false;
            }
            afterMatch = nodeAdaptToSelector(nodePtr, after);
            parent = (*nodePtr)->parent;
            beforeMatch = nodeAdaptToSelector(&parent, before);
            if (before && afterMatch) {
                *nodePtr = parent;
            }
            return beforeMatch && afterMatch;
        }
        selectors = selector->getNormalInhericalList();
        if (selectors.size() == 2) {
            Selector* before = *selectors.begin();
            Selector* after = *--selectors.end();
            bool afterMatch = false;
            bool beforeMatch = false;
            afterMatch = nodeAdaptToSelector(nodePtr, after);
            if (!afterMatch) {
                return afterMatch;
            }
            GumboNode* parent = node->parent;
            while(parent) {
                beforeMatch = nodeAdaptToSelector(&parent, before) || beforeMatch;
                if (beforeMatch) {
                    break;
                }
                parent = parent->parent;
            }
            *nodePtr = parent;
            return beforeMatch && afterMatch;
        }
        return false;
    }
    
}
