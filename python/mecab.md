### 事前準備

sudo apt-get install mecab mecab-ipadic-utf8  
sudo apt-get install python-mecab

http://taku910.github.io/mecab/

### test

```python
# coding: utf-8
import sys
import MeCab

mecab = MeCab.Tagger("-Ochasen")

print(mecab.parse("すもももももももものうち"))
```
