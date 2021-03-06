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

package com.mosync.internal.android.extensions;

import com.mosync.api.CString;
import com.mosync.api.Pointer;

public class CStringImpl extends CString {

	public CStringImpl(int addr, int maxLen) {
		super(addr, maxLen);
	}

	protected String resolve() {
		return StringType.unmarshalCString(addr, maxLen);
	}

	public void set(String str, int maxLen) {
		StringType.marshalCString(addr, str, maxLen);
	}

	@Override
	public Storage getStorage() {
		return Storage.CHAR;
	}
}
