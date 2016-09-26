#include<windows.h>
#define WM_GETMINMAXINFO 0x0024

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("labwork#1");
    HWND     hwnd;
    MSG      msg;
    WNDCLASS wndclass;


    wndclass.style = CS_HREDRAW | CS_VREDRAW ;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    RegisterClass (&wndclass);

    hwnd = CreateWindow(szAppName, TEXT ("First Laboratory Work on Windows Programming"), WS_OVERLAPPEDWINDOW,
                        0, 0, 1200, 720, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam ;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc ;
    PAINTSTRUCT ps ;
    RECT        rect ;
    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint (hwnd, &ps) ;
        GetClientRect (hwnd, &rect) ;
        DrawText (hdc, TEXT ("Done with Pride and Prejudice by Mashaev Iulian"), -1, &rect,
                  DT_SINGLELINE | DT_CENTER | DT_VCENTER ) ;
        EndPaint (hwnd, &ps) ;
        return 0 ;

    case WM_DESTROY:
        PostQuitMessage (0) ;
        return 0 ;
    /*case WM_GETMINMAXINFO:
    {
        LPMINMAXINFO pInfo = (LPMINMAXINFO)lParam;
        POINT point;
        point.x=1200;
        point.y=720;
        pInfo->ptMinTrackSize=point;
        return 0;
    }*/
    case WM_RBUTTONDOWN:
        MessageBox (NULL, TEXT ("You pressed right mouse button"), TEXT ("Notitification"), 1) ;
        return 0;
    case WM_CLOSE:
        MessageBox (NULL, TEXT ("Sure?"), TEXT ("Exit"), 0) ;
        PostQuitMessage (0) ;
        return 0;
    }
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}
