#!/bin/bash

pseudosystems_branch='ftp://lia@pseudosystems.org@ftp.pseudosystems.org/var/csd/cs540/branch'

function bazaar_push {
    local branch="$1"
    bzr push "$branch"
}

function bazaar_pull {
    local branch="$1"
    bzr pull --local "$branch"
}

branches=(
    'sftp://TURBO_X@shadowx/tmp/CS540/'
    'sftp://TURBO_X@shadowx/cygdrive/f/repos/sin/trunk/'
    'sftp://TURBO_X@shadowx/cygdrive/c/Temp/CS540_bzr/'
    'sftp://TURBO_X@shadowx/cygdrive/e/repos/sin/'
)

if [ "$1" = 'pls' ] # pull-shadowx
then    bazaar_pull "${branches[2]}"

else

    #bzr pull 'https://139.91.186.143:8443/svn/CS-540/trunk'
    bzr up

    for branch in "${branches[@]}"
    do  bazaar_push "$branch" &
    done

    if [ "$1" = 'all' ]
    then bazaar_push "$pseudosystems_branch" 
    fi

fi


wait



