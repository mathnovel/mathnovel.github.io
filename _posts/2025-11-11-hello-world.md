---
title: "如何在 Minimal Mistakes 中添加文章"  # 文章标题（支持中文，需加引号）
date: 2025-11-11 15:30:00  # 发布时间（格式：YYYY-MM-DD HH:MM:SS，可覆盖文件名中的日期）
categories:  # 分类（数组形式，可多个）
  - tech
  - AI
tags:  # 标签（数组形式，可多个）
  - DL
  - RL
layout: single  # 固定值，指定使用主题的「单篇文章」布局（必须设置）
author_profile: true  # 是否显示作者信息栏（true/false，默认false）
excerpt: "first arctile"  # 首页展示的摘要（可选，不填则默认截取正文前150字）
header:  # 文章头部大图（可选）
  overlay_image: /assets/images/post-header.jpg  # 图片路径（需先将图片放在 /assets/images/ 文件夹）
  overlay_filter: 0.5  # 图片透明度（0-1，值越大越暗）
  caption: "封面图来源：[Unsplash](https://unsplash.com)"  # 图片说明（可选）
---


# hello world

````py
print("Hello Minimal Mistakes!")

````

必填参数：title、date、layout: single（这三个缺失会导致文章样式错乱）。
可选参数：categories、tags（用于分类和标签页索引）、excerpt（优化首页展示）、header（添加头部大图，增强美观）等。
（2）正文内容（Markdown 格式）
Front Matter 下方就是文章正文，用标准 Markdown 语法编写即可，minimal-mistakes 支持丰富的格式：
标题：# 一级标题、## 二级标题 等
加粗 / 斜体：**加粗**、*斜体*
列表：- 项目1（无序列表）、1. 项目1（有序列表）
图片：![图片描述](/assets/images/图片名.jpg)（图片需放在 /assets/images/ 文件夹，路径用相对路径）
代码块：用 ``` 包裹，例如：

````py
print("Hello Minimal Mistakes!")
````

引用：> 这是一段引用
4. 预览文章（可选）
本地预览：如果本地安装了 Jekyll，在仓库根目录运行 bundle exec jekyll serve，访问 http://localhost:4000 即可实时查看（修改内容后刷新页面生效）。
GitHub 预览：直接将文件提交到仓库，等待 1-2 分钟，访问 用户名.github.io 即可看到新文章（首页会自动更新列表）。
5. 发布文章
将编写好的 .md 文件上传到 _posts 文件夹，通过 GitHub 网页端「Commit」或本地 git push 提交，文章会自动发布。