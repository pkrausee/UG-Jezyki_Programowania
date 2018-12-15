// LAB6.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "LAB6.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Witaj(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB6, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB6));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB6));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB6);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

VOID domek(HDC hdc)
{
	HBRUSH hbrush;
	HPEN hpen;
	RECT rect = { 110, 10, 200, 80 };
	POINT pt[4] = { 800,400,400,300,600,400,600,40 };



	//To jest domek
	hpen = CreatePen(PS_SOLID, 4,RGB(0, 97, 231));
	SelectObject(hdc, hpen);
	Rectangle(hdc, 400, 200, 900, 400);
	DeleteObject(hpen);

	//To sa drzwi
	hpen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, hpen);
	Rectangle(hdc, 625, 300, 695, 400);
	DeleteObject(hpen);

	//To jest klamka
	hpen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, hpen);
	Rectangle(hdc, 680, 349, 690, 350);
	DeleteObject(hpen);

	//To jest okno
	hpen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, hpen);
	hbrush = CreateSolidBrush(RGB(0, 0, 250));
	SelectObject(hdc, hbrush);
	Rectangle(hdc, 470, 240, 550, 300);
	DeleteObject(hpen);

	//To jest okno
	hpen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, hpen);
	Rectangle(hdc, 750, 240, 830, 300);
	DeleteObject(hpen);
	DeleteObject(hbrush);

	//To jest dach
	hbrush = CreateSolidBrush(RGB(91, 0, 0));
	SelectObject(hdc, hbrush);
	hpen = CreatePen(PS_SOLID, 4, RGB(90, 0, 0));
	SelectObject(hdc, hpen);
	POINT vertices[] = { {900, 199}, {400, 199}, {650, 99} };
	Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
	DeleteObject(hpen);
	DeleteObject(hbrush);

	//To jest p³ot
	hpen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, hpen);
	int i;
	for (i = 0; i < 1500; i+=25)
	{
		Rectangle(hdc, 10+i, 500, 30+i, 600);
		DeleteObject(hpen);
	}

	for(int y = 0; y < 150; y++)
		for(int	x = 0; x < 150; x++)
			if((x - 75) *(x - 75) + (y - 75) *(y - 75) < 75 * 75)
				SetPixel(hdc, x + 10, y + 10,RGB(255, 255, 0));







}



//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
		case ID_CZESC: 
			DialogBox(hInst,MAKEINTRESOURCE(IDD_WITAJBOX),hWnd, Witaj);
			break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			domek(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Witaj(HWND hDlg
	,
	UINT
	message
	,
	WPARAM
	wParam
	,
	LPARAM
	lParam
)
{
	UNREFERENCED_PARAMETER
	(
		lParam
	);
	switch
		(
			message
			)
	{
		case
			WM_INITDIALOG
			:
				return
					(
						INT_PTR
						)
					TRUE
					;
				case
					WM_COMMAND
					:
						if
							(
								LOWORD
								(
									wParam
								) ==
								IDOK
								)
						{
							EndDialog(
								hDlg
								,
								LOWORD
								(
									wParam
								));
							return
								(
									INT_PTR
									)
								TRUE
								;
						}
						break
							;
	}
	return
		(
			INT_PTR
			)
		FALSE
		;
}