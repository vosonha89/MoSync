/* Copyright 2013 David Axmark

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/**
 * @file Util.h
 * @author Bogdan Iusco
 *
 * Utility functions for the application.
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <mastring.h>		// C string functions

#define BUF_MAX 256

/**
 * Detects if the current platform is Android.
 * @return true if the platform is Android, false otherwise.
 */
static bool isAndroid()
{
	char platform[BUF_MAX];
	maGetSystemProperty("mosync.device.OS", platform, BUF_MAX);

	if(strcmp(platform, "Android") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * Detects if the current platform is iOS.
 * @return true if the platform is iOS, false otherwise.
 */
static bool isIOS()
{
	char platform[BUF_MAX];
	maGetSystemProperty("mosync.device.OS", platform, BUF_MAX);

	if(strcmp(platform, "iPhone OS") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif /* UTIL_H_ */
