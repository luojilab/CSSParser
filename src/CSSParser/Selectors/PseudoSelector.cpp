//
//  PseudoSelector.cpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#include "PseudoSelector.hpp"

namespace future {

    PseudoSelector::~PseudoSelector()
    {
        delete m_parameter;
        m_parameter = NULL;
    }
    
	bool PseudoSelector::isBaseSelector()
	{
		return true;
	}

	int PseudoSelector::weight()
	{
		return 10;
	}
    
    void PseudoSelector::setParameter(future::PseudoSelector::Parameter *p)
    {
        if (m_parameter == p) {
            return;
        }
        if (m_parameter) {
            delete m_parameter;
        }
        m_parameter = p;
    }
    
    PseudoSelector::Parameter* PseudoSelector::getParameter()
    {
        return m_parameter;
    }
    
    std::string PseudoSelector::getPseudoData()
    {
        return m_data;
    }
}
