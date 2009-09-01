#!/bin/bash

function bazaar_push {
    local branch="$1"
    bzr push "$branch"
}

branches=(
    'sftp://TURBO_X@shadowx/tmp/CS540/'
    'sftp://TURBO_X@shadowx/cygdrive/f/repos/sin/trunk'
)

bzr pull 'https://139.91.186.143:8443/svn/CS-540/trunk'

for branch in "${branches[@]}"
do  bazaar_push "$branch"
done

wait


