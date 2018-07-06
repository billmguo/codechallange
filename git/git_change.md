1) clone the project
$ cd /var/www
$ git clone git@bitbucket.org:user_name/repository_name.git

2) Create a new branch. It will contain the latest files of your master branch repository
$ git branch new_branch

3) Change git branch to the new_branch
$ git checkout new_branch

4) Do coding, commits, as usual…
$ git add .
$ git commit -m “Initial commit”
$ git push (pushes commits only to “new_branch”)

5) When job is finished on this branch, merge with “master” branch:

$ git merge master
$ git checkout master (goes to master branch)
$ git merge development (merges files in localhost. Master shouldn’t have any  commits ahead, otherwise there will be a need for pull and merging code by hands!)
$ git push (pushes all “new_branch” commits to both branches - “master” and “new_branch”)
