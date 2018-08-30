//
//  PseudoSelector.cpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#include "PseudoSelector.hpp"

namespace future {

	bool PseudoSelector::isBaseSelector()
	{
		return true;
	}

	int PseudoSelector::weight()
	{
		return 10;
	}
}
