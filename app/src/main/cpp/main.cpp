#include "DxLib.h"
#include "Bullet.h"
#include <memory>
#include <list>
#include "Utils.h"
#include "Define.h"

using namespace std;

#include "android/log.h"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "TAG", __VA_ARGS__)

// プログラムは android_main から始まります
int android_main( void )
{
    int buf[8];

    SetGraphMode(WIN_W, WIN_H, 32);

    if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
    {
        return -1 ;			// エラーが起きたら直ちに終了
    }
    LoadDivGraph("bullet.png", 8, 8, 1, 62, 62, buf);
    SetDrawScreen( DX_SCREEN_BACK );

    list<shared_ptr<Bullet>> bulletList;
    for(int i=0; i<10000; i++) {
        auto b = make_shared<Bullet>(buf[0]);
        b->x = WIN_W / 2;
        b->y = WIN_H / 2;
        b->ang = randf2(PI);
        b->v = 1 + randf2(0.99);
        bulletList.emplace_back(b);
    }
    while(!ScreenFlip()&&!ProcessMessage()&&!ClearDrawScreen()){
        auto tm = GetNowCount();
        for (auto it = bulletList.begin(); it != bulletList.end();) {
            if (!(*it)->update()) {
                it = bulletList.erase(it);
                continue;
            }
            (*it)->draw();
            it++;
        }
        printfDx("%d\n", GetNowCount()-tm);
    }

    WaitKey() ;				// キー入力待ち

    DxLib_End() ;				// ＤＸライブラリ使用の終了処理

    return 0 ;					// ソフトの終了
}