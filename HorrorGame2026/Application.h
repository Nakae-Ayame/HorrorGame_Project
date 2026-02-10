#pragma once
#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include <cstdint>
//#include "DebugRenderer.h"
//#include "Game.h"

class Application
{
public:
    Application(uint32_t width, uint32_t height) //コンストラクタ
    {
        m_Height = height;  //縦幅
        m_Width = width;    //横幅

        timeBeginPeriod(1);
    }

    ~Application()      //デストラクタ
    {
        timeEndPeriod(1);//タイマーを通常に戻す
    }

    void Run();       //アプリケーション全体の行動


    //----------------Get関数----------------------
    static uint32_t GetWidth() { return m_Width; }      //横幅を取得する
    static uint32_t GetHeight(){ return m_Height; }     //縦幅を取得する
    static HWND GetWindow(){ return m_hWnd; }           //ウィンドウハンドルを取得
    static HINSTANCE GetHInstance(){ return m_hInst; }  //インスタンスハンドルを取得
    static float GetDeltaTime(){ return m_DeltaTime; }

    static void HideCursorAndClip();   // マウスカーソルを非表示＆固定
    static void ShowCursorAndRelease(); // マウスカーソルを表示＆固定解除

private:
    static HINSTANCE   m_hInst;    //インスタンスハンドル
    static HWND        m_hWnd;     //ウィンドウハンドル
    static uint32_t    m_Width;    //ウィンドウの横幅
    static uint32_t    m_Height;   //ウィンドウの縦幅 
    static float       m_DeltaTime;

    static bool InitApp();   //アプリケーションの初期化
    static void UninitApp(); //アプリケーションの終了処理
    static bool InitWnd();   //ウィンドウの初期化
    static void UninitWnd(); //ウィンドウの終了処理
    static void MainLoop();  //ゲームのメインループ

    //ウィンドウプロシージャ
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
};