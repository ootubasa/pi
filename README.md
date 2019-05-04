# pi

円周率を求めるよ！

## やったこと

1. WSLを使ってみた
    * [WSL（Windows Subsystem for Linux）を使ってみた](https://qiita.com/Brutus/items/f26af71d3cc6f50d1640)

    ディストリビューションはUbuntuにしたよ！

    ``` sh
    sudo apt update
    sudo apt upgrade
    sudo apt autoremove
    ```

2. GMPおよびMPFRを使えるようにした
    * [Ubuntuにgcc4.2をソースからインストール](http://d.hatena.ne.jp/seinzumtode/20140730/1406702305)

    ``` sh
    sudo apt install libgmp-dev
    sudo apt install libmpfr-dev
    ```

    * GMPのテスト
        * [円周率を1億桁計算しました！ ― その試行錯誤の詳しい経緯と結果 ー](https://itchyny.hatenablog.com/entry/20120304/1330870932)

        ``` sh
        gcc test-gmp.c -lgmp
        ./a.out
        ```

    * MPFRのテスト
        * [MPFRについて：任意精度数値計算ライブラリ](https://etc2day-linux.blogspot.com/2014/06/mpfr.html)

        ``` sh
        gcc test-mpfr.c -lmpfr -lbmp
        ./a.out

        ```
3. 円周率を求めてみる
    1. アルキメデス
    ```math
    a_0=3,b_0=2\sqrt(3)
    ```