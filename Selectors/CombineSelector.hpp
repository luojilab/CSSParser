//
//  CombineSelector.hpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#ifndef CombineSelector_hpp
#define CombineSelector_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include "Selector.hpp"

namespace future {
    class CombineSelector: public Selector {
    public:
        CombineSelector()
        {
            m_selectorType = Selector::CombineSelector;
        }
        ~CombineSelector();
        void initialInstanceSiblingList(Selector* head, Selector* sibling);
        void initialNormalSiblingList(Selector* head, Selector* sibling);
        void initialInstanceInhericalList(Selector* root, Selector* child);
        void initialNormalInhericalList(Selector* root, Selector* child);
        bool isBaseSelector();
        int weight();
        Selector* getBefore();
        Selector* getAfter();
        inline std::list<Selector *> getInstanceSiblingList()
		{
        	return m_instanceSiblingList;
		}

        inline std::list<Selector *> getNormalSiblingList()
		{
        	return m_normalSiblingList;
		}

        inline std::list<Selector *> getInstanceInhericalList()
		{
        	return m_instanceInhericalList;
		}

        inline std::list<Selector *> getNormalInhericalList()
		{
        	return m_normalInhericalList;
		}

    private:
        std::list<Selector *> m_instanceSiblingList;
        std::list<Selector *> m_normalSiblingList;
        std::list<Selector *> m_instanceInhericalList;
        std::list<Selector *> m_normalInhericalList;
    };
}

#endif /* CombineSelector_hpp */
