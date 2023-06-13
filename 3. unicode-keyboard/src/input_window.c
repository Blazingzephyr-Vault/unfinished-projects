////////////////////////////////////////////////////////////
// MIT License
//
// Copyright(c) 2023 blazingzephyr
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "input_window.h"

/// <summary>
/// Window handle.
/// </summary>
HWND hwnd;

/// <summary>
/// Registers the 'UnicodeInput' window class.
/// </summary>
/// <param name="callback">A callback used to proccess window messages.</param>
void RegisterInputClass(WNDPROC callback)
{
    WNDCLASSEX wcx = { 0 };
    wcx.cbSize = sizeof(WNDCLASSEX);
    wcx.lpfnWndProc = callback;
    wcx.hInstance = NULL;
    wcx.lpszClassName = TEXT("UnicodeInput");

    RegisterClassEx(&wcx);
}


/// <summary>
/// Creates an input-only window.
/// </summary>
void CreateInputWindow()
{
    hwnd = CreateWindowEx(0, TEXT("UnicodeInput"), NULL, WS_EX_TOPMOST, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);
    ShowWindow(hwnd, 1);
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW);
}


/// <summary>
/// Creates a raw input device.
/// </summary>
void RegisterInputDevice()
{
    RAWINPUTDEVICE rid = { 0 };
    rid.usUsagePage = 0x01;
    rid.usUsage = 0x06;
    rid.dwFlags = RIDEV_INPUTSINK | RIDEV_NOHOTKEYS;
    rid.hwndTarget = hwnd;

    RegisterRawInputDevices(&rid, 1, sizeof(RAWINPUTDEVICE));
}


/// <summary>
/// Runs the message loop.
/// </summary>
void MessageLoop()
{
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}


/// <summary>
/// Manages the creation of a Unicode input-only window.
/// </summary>
/// <param name="callback">A callback used to proccess window messages.</param>
void ManageWindow(WNDPROC callback)
{
    RegisterInputClass(callback);
    CreateInputWindow();
    RegisterInputDevice();
    MessageLoop();
}