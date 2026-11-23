# 岩波講座ソフトウェア科学「アルゴリズムとデータ構造」メモ

Pascalのサンプルコードを、C言語に書き直したものです。

## 構成

| フォルダ | 内容 |
|---|---|
| `chapter01/` | 第1章 アルゴリズムと計算量 |

### 第1章

`chapter01/gcd.c` — Euclidの互除法（p.3〜4）

- `gcd_goto`: goto 版（手順書に忠実な書き方）
- `gcd_repeat`: repeat ... until 版（Pascalらしい書き方。Cでは do-while）
- `gcd_rec`: 再帰版（変数 r が不要）

`chapter01/notes-1.1.md` — 1.1「アルゴリズムの正しさ」のまとめ（復習問題1.1）

`chapter01/invariant.c` — ループ不変条件を `assert` で確かめる実験（互除法・階乗）

## ビルドと実行

```sh
cd chapter01
make run    # gcd.c
make check  # invariant.c
```
