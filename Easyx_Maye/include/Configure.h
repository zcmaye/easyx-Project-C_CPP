#pragma once

#ifdef  UNICODE
#undef UNICODE
#endif //  UNICODE

#ifdef _DEBUG
#include<iostream>
#define plog printf
#else
#define plog 
#endif // DEBUG
 
#include<easyx.h>
#include<string>
#include"Timer.h"
#include"commonutils/Font.h"

