# GetFP

for Windows

## これは何

相対パス名を絶対パス名に変換して標準出力に出力します。

## 書式

```dos
GetFP [相対パス名]
```

第一引数には相対パス名を指定します。
引数を省略した場合はカレントディレクトリ (`.`) を選択したものとして扱います。
第二引数以降は無視されます。

## 戻り値

戻り値|ステータス
:-:|:-
0|パスは有効です
1|無効なパスです / ファイルは存在しません
-1|絶対パスを正しく出力できなかった恐れがあります

## 活用例

```dos
DOSKEY MYWGET=FOR /F "USERBACKQ" %%A IN (`GetFP $2`) DO BITSADMIN /TRANSFER HTMLGET $1 %%A
```
としてマクロを組み、
```dos
MYWGET httpから始まるURI 保存先ファイル名
```
と実行すると簡易的な `wget` コマンドとして WEB 上のファイルを取得できます。
ただし、取得先が `Content-Size` を報告していることが必要です(?)。