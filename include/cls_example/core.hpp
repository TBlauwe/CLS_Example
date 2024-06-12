/*****************************************************************//**
@file   core.hpp
@brief  Main file.

@defgroup CLS_Example Topic's title

@details 

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. 
Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. 
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

@example getting_started.cpp
This is an example of how to get started with the library.

@author TBlauwe
@date   12, June 2024
 *********************************************************************/
#pragma once
#include <cls_example/export.hpp>


/**
    @namespace CLS_Example
    @brief Library namespace
**/
namespace CLS_Example
{
	/**
		@brief A simple function returning an int.
		@return Always 1;
	**/
	CLS_EXAMPLE_EXPORT
    int success();
}
