#!/bin/bash

pseudosystems_branch='ftp://lia@pseudosystems.org@ftp.pseudosystems.org/var/csd/cs540/branch'

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

if [ "$1" = 'all' ]
then bazaar_push "$pseudosystems_branch" 
fi

wait


