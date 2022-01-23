
#!/bin/bash

problem_name=$1
ext_name=$2
file=$3
relative_file_dir_name=$4
contest_name=${relative_file_dir_name##*/}
test_dir=samples/${contest_name}/${problem_name}
url=https://atcoder.jp/contests/${contest_name}/tasks/${contest_name}_${problem_name}

# make sample directory
if [ ! -e ${test_dir} ]; then
    ~/opt/anaconda3/bin/oj dl -d ${test_dir} ${url}
fi

# test
/usr/bin/g++ -std=c++14 ${file} && ~/opt/anaconda3/bin/oj test -c "./a.out" -d ${test_dir}
