//============================================================================
// Name        : Final.cpp
// Author      : Paweł
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <Windows.h>
#include <WindowsX.h>
#include <iostream>
#include <sstream>
#include "../inc/Function.h"
#include "../inc/SyntaxCorrector.h"
#include "../inc/MainFunction.h"
using namespace std;

struct RECTf{
	float left, top, right, bottom;
};

HWND hwnd;
HWND funEdit, x1Edit, x2Edit, gogo;
HDC hdc;
wchar_t* className = L"japa18_23";
wchar_t* windowName = L"Final Project";
RECT r = { 42, 22, 1032, 522 };
RECT xr = { 42, 0, 1032, 20 };
RECT yr = { 0, 22, 40, 522 };
RECTf funr;
float* points = new float[1000];
bool* isPoint = new bool[1000];
int width, height;

LRESULT WINAPI windowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
void registerClass(){
	WNDCLASSEX wc; 
	ZeroMemory(&wc, sizeof(wc)); 
	wc.style=CS_CLASSDC; 
	wc.lpszClassName=className; 
	wc.lpfnWndProc=windowProc; 	
	wc.cbSize=sizeof(wc); 
	wc.hCursor=LoadCursor(0, IDC_ARROW); 
	wc.hIcon=LoadIcon(0, IDI_APPLICATION); 	
	wc.hbrBackground=(HBRUSH)COLOR_WINDOW; 
	RegisterClassEx(&wc);
}
void createWindow(){
	hwnd = CreateWindowEx(0, className, windowName, WS_OVERLAPPEDWINDOW, 0, 0,
							1050, r.bottom+70, 0, 0, 0, 0);						  
	ShowWindow(hwnd, SW_SHOW); 		
	funEdit = CreateWindowEx(WS_EX_CLIENTEDGE, L"edit", L"sin(ln(cos(x^(cos(3x)))))", WS_CHILD|WS_VISIBLE|WS_BORDER, r.left-40, r.bottom+3, 340, 30, hwnd, 0, 0, 0);	
	x1Edit = CreateWindowEx(WS_EX_CLIENTEDGE, L"edit", L"0", WS_CHILD|WS_VISIBLE|WS_BORDER, r.left+300, r.bottom+3, 50, 30, hwnd, 0, 0, 0);
	x2Edit = CreateWindowEx(WS_EX_CLIENTEDGE, L"edit", L"4", WS_CHILD|WS_VISIBLE|WS_BORDER, r.left+350, r.bottom+3, 50, 30, hwnd, 0, 0, 0);
	gogo = CreateWindowEx(WS_EX_CLIENTEDGE, L"button", L"Draw!", WS_CHILD|WS_VISIBLE|WS_BORDER, r.left+400, r.bottom+3, 50, 30, hwnd, (HMENU)1, 0, 0);
}
void initDC(){
	hdc = GetDC(hwnd);
	
	Rectangle(hdc, r.left-1, r.top-1, r.right+1, r.bottom+1);		
	FillRect(hdc, &r, WHITE_BRUSH);	
	TextOutA(hdc, 8, 2, ": - )", 5);
}
void drawFunction(string source, int x1, int x2){	
	
	float max=-999, min=999;
	float dx = (x2-x1)/1000.0f;
	
	for(int i=0; i<1000; i+=5){
		try{
			float x = (float)x1 + ((float)i)*(x2-x1)/1000.0;
			Function::setX(x+dx);
			MainFunction mf(source);			
			try{
				points[i] = (float)mf;
				Function::setX(x);
				MainFunction mf2(source);
				points[i] = (points[i] - (float)mf2)/dx;

				isPoint[i] = true;
			}catch(const char* e){
				isPoint[i] = false;
			}
		}catch(const char* e){
			MessageBoxA(0, "syntax error", "Error", 0);
			return;
		}		

		if(i==0 && isPoint[i]){
			min = 1000;
			max = -1000;
		}else{
			if(i!=0 && isPoint[i]){
				if(points[i] > max){
					max = points[i];
					if(max > 1000){
						max = 1000;
					}
				}
				if(points[i] < min){
					min = points[i];
					if(min < -1000){
						min = -1000;
					}
				}
			}
		}
	}
	FillRect(hdc, &xr, 0);
	for(int i=0; i<11; ++i){		
		stringstream ss;
		ss.precision(2);
		ss<<fixed<<(x1 + i*(float)(x2-x1)/10.0);
		TextOutA(hdc, xr.left+i*94, xr.top, ss.str().c_str(), ss.str().length());
	}
	FillRect(hdc, &yr, 0);
	for(int i=0; i<11; ++i){		
		stringstream ss;
		ss.precision(2);
		ss<<fixed<<(min + i*(float)(max-min)/10.0);
		TextOutA(hdc, yr.left, yr.top+(10-i)*48, ss.str().c_str(), ss.str().length());
	}	
	funr.top=max; funr.bottom=min; funr.left=x1; funr.right=x2;
	if(max*min<0){
		MoveToEx(hdc, r.left-1, r.bottom - (int)((-min)/(max-min)*500.0), 0);
		LineTo(hdc, r.right+1, r.bottom - (int)((-min)/(max-min)*500.0));
	}
	if(x1*x2<0){
		int x0 = r.left + (int)((0-x1)/(float)(x2-x1)*1000.0);
		MoveToEx(hdc, x0, r.top-1, 0);
		LineTo(hdc, x0, r.bottom+1);
	}
	bool move = true;
	for(int i=0; i<1000; i+=5){
		if(move){
			if(isPoint[i]){
				if(points[i]<999 && points[i]>-999){
					int y = r.bottom-(int)((points[i]-min)/(max-min)*500.0);
					MoveToEx(hdc, r.left+i, y, 0);
					move = false;
				}else{
					move = true;
				}
			}else{
				continue;
			}
		}else{
			if(isPoint[i]){
				LineTo(hdc, r.left+i, r.bottom-(int)((points[i]-min)/(max-min)*500));
			}else{
				move = true;
			}
		}
	}
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT){
	registerClass();
	createWindow();
	initDC();
	drawFunction("sin(ln(cos(x^(cos(3x)))))", 0, 4);

	MSG msg; 
	ZeroMemory(&msg, sizeof(msg)); 
	
	while(msg.message!=WM_QUIT){
		if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
			DispatchMessage(&msg); 
			TranslateMessage(&msg); 
		}else{
			// :)
		}
	}
	delete[] isPoint;
	delete[] points;
	return 0;
}

LRESULT WINAPI windowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){		
	switch(msg){	
	case WM_KEYUP:
		if(wp == VK_ESCAPE){
			PostQuitMessage(0);
			return 0;
		}
		break;
	case WM_COMMAND:
		if(wp == 1){
			int funStrLength = GetWindowTextLength(funEdit)+1;
			char *funStr = new char[funStrLength];
			GetWindowTextA(funEdit, funStr, funStrLength);

			int x1StrLength = GetWindowTextLength(x1Edit)+1;
			char *x1Str = new char[x1StrLength];
			GetWindowTextA(x1Edit, x1Str, x1StrLength);

			int x2StrLength = GetWindowTextLength(x2Edit)+1;
			char *x2Str = new char[x2StrLength];
			GetWindowTextA(x2Edit, x2Str, x2StrLength);

			FillRect(hdc, &r, 0);			
			drawFunction(string(funStr), atoi(x1Str), atoi(x2Str));
			delete[] funStr;
			delete[] x1Str;
			delete[] x2Str;
		}
		break;
	case WM_MOUSEMOVE:
		POINT p;		
		p.x=GET_X_LPARAM(lp); 
		p.y=GET_Y_LPARAM(lp);
		
		if((p.x>=r.left&&p.x<=r.right)&&(p.y>=r.top&&p.y<=r.bottom)){			
			stringstream ss;
			ss.precision(2);
			ss<<fixed<<"FinalProject("<<funr.left+(funr.right-funr.left)*(p.x-r.left)/(float)(r.right-r.left)<<" , "<<funr.top+(funr.bottom-funr.top)*(p.y-r.top)/(float)(r.bottom-r.top)<<")";
			SetWindowTextA(hwnd, ss.str().c_str());
		}		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp); 
}