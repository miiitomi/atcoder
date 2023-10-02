export $(cat .env | grep -v ^# | xargs)
~/.local/bin/oj login -u $ATCODER_USER -p $ATCODER_PASS "https://atcoder.jp/"
