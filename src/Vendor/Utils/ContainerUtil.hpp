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
    /*
     * Container type must be STL Sequence
     * because of the unique and forword iterator conception
     */
    template<class T>
    void CleanContainer(T& container)
    {
        container.unique();
        typename T::iterator it = container.begin();
        typename T::iterator end = container.end();
        while (it != end) {
            delete *it++;
        }
        container.clear();
    }
}

#endif /* ContainerUtil_hpp */
