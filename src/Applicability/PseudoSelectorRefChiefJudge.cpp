//
//  PseudoSelectorRefChiefJudge.cpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/9/12.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#include "PseudoSelectorRefChiefJudge.hpp"
#include <string>
#include "PseudoSelector.hpp"

const std::string P_LINK = "link";
const std::string P_VISITED = "visited";
const std::string P_HOVER = "hover";
const std::string P_ACTIVE = "active";
const std::string P_FOCUS = "focus";
const std::string P_ENABLE = "enable";
const std::string P_DISABLE = "disable";
const std::string P_CHECKED = "checked";
const std::string P_INDETERMINATE = "indeterminate";
const std::string P_ROOT = "root";
const std::string P_NTHCHILD = "nth-child";
const std::string P_NTHLASTCHILD = "nth-last-child";
const std::string P_NTHOFTYPE = "nth-of-type";
const std::string P_NTHLASTOFTYPE = "nth-last-of-type";
const std::string P_FIRSTCHILD = "first-child";
const std::string P_LASTCHILD = "last-child";
const std::string P_FIRSTOFTYPE = "first-of-type";
const std::string P_LASTOFTYPE = "last-of-type";
const std::string P_ONLYCHILD = "only-child";
const std::string P_ONLYOFTYPE = "only-of-type";
const std::string P_EMPTY = "empty";
const std::string P_TARGET = "target";
const std::string P_LANG = "lang";

namespace future {
    bool PseudoSelectorRefChiefJudge::nodeAdaptToPseudo(GumboNode *node, future::PseudoSelector *selector)
    {
        std::string ruleData = selector->getPseudoData();
        if (ruleData.empty()) {
            return false;
        }
        if (ruleData == "") {
        }
        return true;
    }
}
