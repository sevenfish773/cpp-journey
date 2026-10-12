# Git 中文速查表（每天要用）

> 你只需要记住 **5 条**命令就能撑过 90% 的场景。
> 其他都是备用，用到再查。

---

## 一、每天必用的 5 条（背下来）

```powershell
git status                    # 看我改了哪些文件（最常用，随时敲）
git add .                     # 把所有改动加入"待提交"
git commit -m "做了什么"       # 提交，生成一个存档点
git push                      # 推到 GitHub
git log --oneline -10         # 看我最近 10 次提交
```

**标准流程**：写代码 → `git status` 看一眼 → `git add .` → `git commit -m "..."` → `git push`

---

## 二、commit 信息怎么写

| ❌ 别这样写 | ✅ 这样写 |
|---|---|
| `update` | `week01: 手写 my_strdup` |
| `修改` | `week01: 修复 my_strcat 未处理空字符串的 bug` |
| `111` | `leetcode: 0001 两数之和，哈希表 O(n)` |
| `a` | `week02: class String 加上移动构造` |

**格式建议**：`范围: 做了什么`

面试官会翻你的提交历史。写得清楚 = 加分；一片 `update` = 减分。

---

## 三、遇到问题时的命令

### 我改乱了，想撤销还没提交的改动

```powershell
git restore 文件名            # 只撤销某个文件
git restore .                 # 撤销全部未提交的改动（⚠️ 不可恢复）
```

### 我 commit 完了，但发现漏了文件

```powershell
git add 漏掉的文件
git commit --amend --no-edit  # 合并进上一次提交，不改提交信息
```

### 我 commit 信息写错了

```powershell
git commit --amend -m "新的正确信息"
```

### 我想看某个文件具体改了哪几行

```powershell
git diff                      # 未提交的改动
git diff HEAD                 # 已提交 vs 工作区
git show 提交号                # 看某次提交的完整内容
```

### 我想回到某个历史版本看看（不删东西）

```powershell
git log --oneline             # 找到目标提交号，如 a1b2c3d
git checkout a1b2c3d          # 切过去看看（只读状态）
git checkout main             # 看完切回来
```

### 我 push 被拒绝了（remote 比你新）

```powershell
git pull --rebase             # 先把远端的改动拉下来
git push                      # 再推
```

> 别轻易用 `git push -f` —— 会**覆盖远端历史**，可能丢掉东西。只有你自己一个人的仓库、且明确知道在干什么时才用。

---

## 四、分支（前期用不到，但实习第一天就要用）

```powershell
git switch -c feature/xxx     # 新建并切到分支（做新功能时）
git switch main               # 切回主分支
git branch                    # 看所有分支，* 号是当前分支
git merge feature/xxx         # 把分支合并到当前分支
git branch -d feature/xxx     # 删掉已合并的分支
```

> 你现在一个人写练习，**直接在 `main` 上提交就行**。等做正式项目再练分支。

---

## 五、报错速查

| 报错 | 原因 | 解决 |
|---|---|---|
| `not a git repository` | 当前目录不是仓库 | `cd` 到仓库目录，或先 `git init` |
| `Please tell me who you are` | 没配用户名邮箱 | 跑 `git config --global user.name/user.email` |
| `failed to push some refs` | 远端有你没有的提交 | `git pull --rebase` 后再 push |
| `Permission denied (publickey)` | SSH key 没配好 | `ssh -T git@github.com` 测一下 |
| `nothing to commit` | 你没改任何文件 | 正常，去写代码 |
| `LF will be replaced by CRLF` | 换行符提示 | **警告而已，可以忽略** |
| 进了 Vim 出不来 | 默认编辑器是 Vim | 按 `Esc`，输入 `:wq` 回车；或 `:q!` 强退 |

---

## 六、配置命令（一次性，已做过）

```powershell
git config --global user.name  "sevenfish773"
git config --global user.email "3029589214@qq.com"
git config --global init.defaultBranch main
git config --global core.quotepath false      # 中文文件名正常显示
git config --global --list                    # 检查配置
```

---

## 七、一个心态提醒

**出错很正常，Git 几乎不会真的弄丢东西。** 大部分"我以为搞砸了"都能用 `git status` + `git log` 找回来。

唯一要小心的是这两类：`git restore .`（丢弃未提交改动，不可恢复）和 `git push -f`（覆盖远端历史）。**看到 `-f` 或 `--force` 先停下来想 3 秒。**

---

*配合 `cpp-journey` 使用。遇到本表没写的报错，先复制报错去搜，再问 AI。*
