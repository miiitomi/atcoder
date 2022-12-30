
#!/bin/bash

problem_name=$1
file=$2
relative_file_dir_name=$3
contest_name=${relative_file_dir_name##*/}

if [ ${contest_name} = tessoku-book ];
then
    url=https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_${problem_name}
else
    url=https://atcoder.jp/contests/${contest_name}/tasks/${contest_name}_${problem_name}
fi

# submit
~/miniforge3/bin/oj submit --yes ${url} ${file}
