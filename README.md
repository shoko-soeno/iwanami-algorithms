# 岩波講座ソフトウェア科学「アルゴリズムとデータ構造」輪読メモ

輪読会で読んでいる本のPascalのサンプルコードを、C言語に書き直したものです。

## 構成

| フォルダ | 内容 |
|---|---|
| `chapter01/` | 第1章 アルゴリズムと計算量 |

### 第1章

`chapter01/gcd.c` — Euclidの互除法（p.3〜4）

- `gcd_goto`: goto 版（手順書に忠実な書き方）
- `gcd_repeat`: repeat ... until 版（Pascalらしい書き方。Cでは do-while）
- `gcd_rec`: 再帰版（変数 r が不要）

## ビルドと実行

```sh
cd chapter01
make run
```
