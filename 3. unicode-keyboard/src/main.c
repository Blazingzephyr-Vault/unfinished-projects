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
#include <stdio.h>
#include <locale.h>

////////////////////////////////////////////////////////////
LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    if (Msg == WM_INPUTLANGCHANGE)
    {
        printf("A\n");
    }

    if (Msg == WM_INPUT)
    {
        HRAWINPUT hRawInput = (HRAWINPUT)lParam;
        RAWINPUT input = { 0 };
        UINT size = sizeof(input);
        GetRawInputData(hRawInput, RID_INPUT, &input, &size, sizeof(RAWINPUTHEADER));

        printf("vkey: %x, flag: %dn\n", input.data.keyboard.VKey, input.data.keyboard.Flags);
    }

    return DefWindowProc(hWnd, Msg, wParam, lParam);
}

int main()
{
    //IntPtr fore = GetForegroundWindow();
    //uint tpid = GetWindowThreadProcessId(fore, IntPtr.Zero);
    //IntPtr hKL = GetKeyboardLayout(tpid);
    //hKL = (IntPtr)(hKL.ToInt32() & 0x0000FFFF);
    //InputLanguageManager m = InputLanguageManager.Current;
    //m.CurrentInputLanguage = new System.Globalization.CultureInfo(hKL.ToInt32());
    ////IntPtr i = LoadKeyboardLayout(hKL.ToString(), 1);

    //InputLanguage = InputLanguageManager.Current.CurrentInputLanguage.ToString();

    //HWND handle = GetForegroundWindow();
    //DWORD tpid = GetWindowThreadProcessId(handle, 0);
    //HKL hkl = GetKeyboardLayout(tpid);
    //int kl = hkl = (int)(hkl) & 0x0000FFFF;

    //HKL layout = GetKeyboardLayout(GetWindowThreadProcessId(GetForegroundWindow(), 0));
    //printf("%i", layout->unused);

    ManageWindow(WindowProc);

    return 0;
}