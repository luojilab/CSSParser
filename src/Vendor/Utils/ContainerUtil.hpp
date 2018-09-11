//
//  ContainerUtil.hpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/30.
//  Copyright © 2018年 1m0nster. All rights reserved.
//

#ifndef ContainerUtil_hpp
#define ContainerUtil_hpp

#include <stdio.h>

namespace future {
#define CleanContainer(c) c.unique(); _CleanContainer(c); c.clear();
    /*
     * Container type must be STL Sequence
     * because of the unique and forword iterator conception
     */
    template<class T>
    void _CleanContainer(const T& container)
    {
        typename T::const_iterator it = container.begin();
        typename T::const_iterator end = container.end();
        while (it != end) {
            delete *it++;
        }
    }
}

#endif /* ContainerUtil_hpp */
