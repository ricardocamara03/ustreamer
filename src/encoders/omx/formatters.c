/*****************************************************************************
#                                                                            #
#    uStreamer - Lightweight and fast MJPG-HTTP streamer.                    #
#                                                                            #
#    Copyright (C) 2018  Maxim Devaev <mdevaev@gmail.com>                    #
#                                                                            #
#    This program is free software: you can redistribute it and/or modify    #
#    it under the terms of the GNU General Public License as published by    #
#    the Free Software Foundation, either version 3 of the License, or       #
#    (at your option) any later version.                                     #
#                                                                            #
#    This program is distributed in the hope that it will be useful,         #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of          #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           #
#    GNU General Public License for more details.                            #
#                                                                            #
#    You should have received a copy of the GNU General Public License       #
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.  #
#                                                                            #
*****************************************************************************/


#include "formatters.h"

#include <stdio.h>
#include <assert.h>

#include <IL/OMX_IVCommon.h>
#include <IL/OMX_Core.h>

#include "../../tools.h"


#define CASE_TO_STRING(_value) \
	case _value: { return #_value; }

#define CASE_ASSERT(_msg, _value) default: { \
		char *_assert_buf; A_CALLOC(_assert_buf, 128); \
		sprintf(_assert_buf, _msg ": 0x%08x", _value); \
		assert(0 && _assert_buf); \
	}

const char *omx_error_to_string(OMX_ERRORTYPE error) {
	switch (error) {
		CASE_TO_STRING(OMX_ErrorNone);
		CASE_TO_STRING(OMX_ErrorInsufficientResources);
		CASE_TO_STRING(OMX_ErrorUndefined);
		CASE_TO_STRING(OMX_ErrorInvalidComponentName);
		CASE_TO_STRING(OMX_ErrorComponentNotFound);
		CASE_TO_STRING(OMX_ErrorInvalidComponent);
		CASE_TO_STRING(OMX_ErrorBadParameter);
		CASE_TO_STRING(OMX_ErrorNotImplemented);
		CASE_TO_STRING(OMX_ErrorUnderflow);
		CASE_TO_STRING(OMX_ErrorOverflow);
		CASE_TO_STRING(OMX_ErrorHardware);
		CASE_TO_STRING(OMX_ErrorInvalidState);
		CASE_TO_STRING(OMX_ErrorStreamCorrupt);
		CASE_TO_STRING(OMX_ErrorPortsNotCompatible);
		CASE_TO_STRING(OMX_ErrorResourcesLost);
		CASE_TO_STRING(OMX_ErrorNoMore);
		CASE_TO_STRING(OMX_ErrorVersionMismatch);
		CASE_TO_STRING(OMX_ErrorNotReady);
		CASE_TO_STRING(OMX_ErrorTimeout);
		CASE_TO_STRING(OMX_ErrorSameState);
		CASE_TO_STRING(OMX_ErrorResourcesPreempted);
		CASE_TO_STRING(OMX_ErrorPortUnresponsiveDuringAllocation);
		CASE_TO_STRING(OMX_ErrorPortUnresponsiveDuringDeallocation);
		CASE_TO_STRING(OMX_ErrorPortUnresponsiveDuringStop);
		CASE_TO_STRING(OMX_ErrorIncorrectStateTransition);
		default: return "Unknown OMX error";
	}
}

const char *omx_state_to_string(OMX_STATETYPE state) {
	switch (state) {
		CASE_TO_STRING(OMX_StateLoaded);
		CASE_TO_STRING(OMX_StateIdle);
		CASE_TO_STRING(OMX_StateExecuting);
		// cppcheck-suppress constArgument
		// cppcheck-suppress knownArgument
		CASE_ASSERT("Unsupported OMX state", state);
	}
}

#undef CASE_ASSERT
#undef CASE_TO_STRING
