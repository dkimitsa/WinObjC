//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include "XIBObjectInt.h"
#include <climits>

XIBObjectInt::XIBObjectInt(long long val) {
    _val = val;
}

int XIBObjectInt::intValue() {
    return _val;
}

long long XIBObjectInt::longValue() {
    return _val;
}

bool XIBObjectInt::NeedsSerialization() {
    return false;
}

void XIBObjectInt::WriteData(NIBWriter* writer) {
    if (_val >= SCHAR_MIN && _val <= SCHAR_MAX) {
        writer->WriteByte(NIBOBJ_INT8);
        writer->WriteBytes(&_val, 1);
    } else if (_val >= SHRT_MIN && _val <= SHRT_MAX) {
        writer->WriteByte(NIBOBJ_INT16);
        writer->WriteBytes(&_val, 2);
    } else if (_val >= INT_MIN && _val <= INT_MAX) {
        writer->WriteByte(NIBOBJ_INT32);
        writer->WriteBytes(&_val, 4);
    } else {
        writer->WriteByte(NIBOBJ_INT64);
        writer->WriteBytes(&_val, 8);
    }
}

