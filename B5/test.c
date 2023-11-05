#include "pref1.h" // pref_t 構造体と pref_new 関数を定義したヘッダファイル
#include <stdio.h>
#include <stdlib.h>

#define MAX_PREFS 47

int main(void) {
    pref_t *prefs[MAX_PREFS];
    int count = 0;

    for (int i = 0; i < MAX_PREFS; i++) {
        prefs[i] = NULL;
    }

    // 標準入力から県のデータを読み込む
    while ((prefs[count] = pref_new_scan()) != NULL && count < MAX_PREFS) {
        count++;
    }

    // 読み込んだデータを逆順に出力
    for (int i = count - 1; i >= 0; i--) {
        printf("%s %f %d\n", prefs[i]->name, prefs[i]->area, prefs[i]->population);
    }

    // // 使用後、各構造体のメモリを解放
    // for (int i = 0; i < count; i++) {
    //     if (prefs[i] != NULL) {
    //         free(prefs[i]->name); // strdupで確保されたメモリを解放
    //         free(prefs[i]);       // mallocで確保されたメモリを解放
    //         prefs[i] = NULL;      // 解放したポインタをNULLに設定
    //     }
    // }

    return 0;
}
