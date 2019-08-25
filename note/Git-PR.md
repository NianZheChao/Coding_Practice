## 如何正确在GitHub上进行pull request

1. git clone  //将项目clone至本地

2. git checkout -b 新建分支名  //创建新分支

3. git add .  //将内容全部添加到本地git缓存区中

   git add 文件名  //将单个文件变化添加到本地git缓存区

4. git commit -m “修改描述”  //推送修改到本地git库中

5. git remote add upstream git@github.com:author/project.git  //与上游版本库建立联系。

6. git pull <远程主机名> <远程分支名>  //取回远程主机某个分支的更新，再与本地的指定分支合并。（主机名一般为origin）

7. git push <远程主机名> <远程分支名>  //把当前提交到git本地仓库的代码推送到远程主机的某个远程分之上

