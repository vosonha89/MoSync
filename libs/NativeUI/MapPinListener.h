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

/*! \addtogroup NativeUILib
 *  @{
 */

/**
 *  @defgroup NativeUILib Native UI Library
 *  @{
 */

/**
 * @file MapListener.h
 * @author Spiridon Alexandru
 *
 * \brief Listener for Map events.
 */

#ifndef NATIVEUI_MAP_PIN_LISTENER_H_
#define NATIVEUI_MAP_PIN_LISTENER_H_

namespace NativeUI
{
    // Forward declaration.
    class MapPin;

    /**
     * \brief Listener for Map pin events.
     */
    class MapPinListener
    {
    public:
        /**
		 * This method is called when the user clicks on a map pin.
         * @param mapPin The map pin object that generated the event.
         */
        virtual void mapPinClicked(MapPin* mapPin) {};
    };

} // namespace NativeUI

#endif /* NATIVEUI_MAP_PIN_LISTENER_H_ */

/*! @} */
