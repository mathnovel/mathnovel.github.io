
[toc]

----

>2019年，强化学习之父、阿尔伯塔大学教授Richard Sutton发表了后来被AI领域奉为经典的The Bitter lesson，这也是OpenAI研究员的必读文章。
>在这篇文章中，Richard指出，过去 70 年来，AI 研究的一大教训是过于重视人类既有经验和知识，而他认为最大的解决之道是摒弃人类在特定领域的知识，利用大规模算力才是王道。这一思想很快得到了OpenAI首席科学家Ilya Sutskever的共鸣，某种程度上，它也启发了大模型领域所信奉的Scaling Law。
>有趣的是，Richard认为，通过语言大模型方向来实现智能没有前途，他更赞同Yann LeCun关于世界模型的构想，这在目标与核心概念上与其主导的阿尔伯塔计划（Alberta Plan）相一致，尽管不过在具体实现方法上有所区别。
>在他看来，实现AGI需要明确的目标和一个世界模型，并利用这个模型来制定行动计划以实现目标。
>Richard Sutton研究人工智能已长达45年。他非常想弄清大脑的运作方式，为此做了大量跨学科研究，阅读了不同思想家对这一问题的看法，并试图从心理学入手，以找出大脑和计算机科学的运作方式。
>在Craig Smith近期主持的一期播客中，Richard详细介绍了阿尔伯塔计划，目标是打造一个能够从与环境的交互中学习并做规划的具身智能体，这是一个宏大的五年计划。此外，他还深入分析了新算法的发展现状、模拟环境和真实环境之间的权衡以及通用人工智能（AGI）的终极目标。Richard还谈到了与传奇工程师John Carmack的合作。2023年10月，Richard加入了后者创办的AI创业公司Keen Technologies并担任研究员，这家公司旨在2030年实现AGI。

-----

# [译文] 苦涩的教训

英文原文：[The Bitter Lesson](http://www.incompleteideas.net/IncIdeas/BitterLesson.html)

理查德·萨顿（Richard S. Sutton，现代强化学习之父，现任加拿大阿尔伯塔大学教授）

2019年3月13日过去70年人工智能研究领域最重要的一堂课是，只有通用计算方法最终是最有效的，而且优势巨大。根本原因是摩尔定律，更确切地说是，每个计算单元的成本持续呈指数下降。大多数人工智能研究都是假设 Agent 可用的计算量是恒定的（在这种情况下，利用人类知识将是提高性能的唯一方法之一），但是，从较长的时间看，不可避免地会产生大量的计算量。为了在短期内获得有所作为的改善，研究人员试图利用该领域内的人类知识。但长远来看，唯一重要的是利用算力。这两者不必相互对立，但在实践中它们往往会相互对立。时间投入到一种方法上，就没办法投入到另一种方法上，这是对投入一种或另一种方法的心理承诺。而人类知识往往很复杂，不太适合利用好通用算力。有很多的例子表明人工智能研究人员迟迟未能学习这个苦涩的教训，回顾一些最突出的例子很有启发性。

在电脑国际象棋中，1997年击败世界冠军卡斯帕罗夫的方法基于大规模的深度搜索。当时，大多数计算机国际象棋研究人员对此感到沮丧，他们一直致力于利用人类对国际象棋特殊结构的理解的方法，当一种更简单的、基于搜索的、结合特殊的硬件和软件的方法，被证明更有效时，这些基于人类知识的国际象棋研究人员没有虚心接受失败，他们反驳道，“蛮力”搜索可能这次赢了，但这不是一种通用的策略，而且也不是人们玩国际象棋的方式。这些研究人员希望基于人类的行棋思路能够获胜，当没有获胜时他们感到失望。

在电脑围棋中，也出现了类似的研究进展，只是比国际象棋晚了20年。最初的巨大努力是想办法利用人类知识（一千年的棋谱），或围棋游戏的特殊特征，避免用蛮力搜索，但是所有这些努力都被证明是无关紧要的。更糟糕的是，一旦有效地进行了大规模搜索，以及，使用自我对局来学习价值函数（就像在许多其他游戏中一样，在国际象棋中也是如此，尽管这种学习在1997年首次击败世界冠军的项目中并没有发挥重要作用），之前的努力都是负向的。通过 自我对局 以及 通用学习 来学习，就像搜索一样，因为它能够进行大规模的计算。在电脑围棋、电脑国际象棋中，研究人员最初的努力是利用人类的理解（更少的搜索），直到很久以后，通过拥抱搜索和学习，才取得更大的成功。


在语音识别方面，在1970年代，由DARPA（美国国防部高级研究计划局）赞助了一项早期的竞赛。参赛者包括许多利用人类知识的特殊方法——单词、音素、人类声道等等知识。另一方面是更具统计学意义的方法，基于隐马尔可夫模型（HMMs）进行了更多的计算。再次，统计学方法战胜了基于人类知识的方法。这导致了几十年来所有自然语言处理的重大变化，统计学和计算逐渐开始主导该领域。最近深度学习在语音识别领域的兴起是朝着这一方向迈出的最新一步。深度学习方法对人类知识的依赖程度更低，使用更多的计算，加上在巨大的训练集上的学习，以产生更好的语音识别系统。正如游戏中一样，研究人员总是试图让系统按照他们自己的大脑工作的方式工作 —— 他们试图将这些知识放入他们的系统中 —— 但事实证明，当大规模计算变得可用并找到了一种充分利用摩尔定律的方法时，这最终会适得其反，并且浪费了研究人员的时间。


在计算机视觉领域，也存在类似的模式。早期的方法把视觉想象成寻找边缘，或广义柱，或以SIFT特征的形式。但今天，这一切都被抛弃了。现代深度学习神经网络仅使用卷积和某些不变性的概念，并且表现得更好。


这是一个重要的教训。纵观整个人工智能领域，我们仍然没有彻底地吸取它，因为我们继续犯同样的错误。为了看到这一点，并有效地抵制它，我们必须理解这些错误的吸引力。我们必须吸取苦涩的教训，即把我们认为的思维方式构建到系统中是行不通的。苦涩的教训是基于历史观察：
1. 人工智能研究人员经常试图将知识构建到他们的 Agent 中；
2. 这在短期内总是有帮助的，并且对研究人员来说是个人满意的；
3. 但从长远来看，它总会达到一个瓶颈，甚至会阻碍进一步的进展；
4. 突破性的进展最终是通过一种相反的方法实现的，这种方法基于通过搜索和学习来扩展大规模计算。 


最终的成功中夹杂着一丝苦涩和消化不全，因为它比受青睐的、以人为本的方法更成功。

从苦涩的教训中学到的一件事是通用方法的巨大力量，即随着可用算力变得非常大，这些方法会随着计算量的增加可以继续扩展。可以以这种方式近乎无限扩展的两种方法是:<h1>搜索和学习</h1>。


从苦涩的教训中学到的第二个普遍观点是，**人类心灵的实际内容是极其复杂的**，我们不应该再试图找到简单的方法来思考心灵的内容，比如简单地思考空间、物体、多重主体或对称性。所有这些都是任意的、内在复杂的外部世界的一部分。它们不应该被构建，因为它们的复杂性是无止境的；**相反，我们应该只构建可以找到和捕获这种任意复杂性的元方法**。这些方法的关键是它们可以找到很好的近似值，但算法应该是基于我们的方法，而不是我们已经学到的知识。我们希望人工智能 Agent 能够像我们人类一样去发现，而不是在系统里集成我们已经发现的东西。建立在我们已知发现之上只会让我们更难看到如何完成发现过程。
 


------


# The Bitter Lesson

>http://www.incompleteideas.net/IncIdeas/BitterLesson.html


Rich Sutton
March 13, 2019


The biggest lesson that can be read from 70 years of AI research is that general methods that leverage computation are ultimately the most effective, and by a large margin. The ultimate reason for this is Moore's law, or rather its generalization of continued exponentially falling cost per unit of computation. Most AI research has been conducted as if the computation available to the agent were constant (in which case leveraging human knowledge would be one of the only ways to improve performance) but, over a slightly longer time than a typical research project, massively more computation inevitably becomes available. Seeking an improvement that makes a difference in the shorter term, researchers seek to leverage their human knowledge of the domain, but the only thing that matters in the long run is the leveraging of computation. These two need not run counter to each other, but in practice they tend to. Time spent on one is time not spent on the other. There are psychological commitments to investment in one approach or the other. And the human-knowledge approach tends to complicate methods in ways that make them less suited to taking advantage of general methods leveraging computation.  There were many examples of AI researchers' belated learning of this bitter lesson, and it is instructive to review some of the most prominent.

In computer chess, the methods that defeated the world champion, Kasparov, in 1997, were based on massive, deep search. At the time, this was looked upon with dismay by the majority of computer-chess researchers who had pursued methods that leveraged human understanding of the special structure of chess. When a simpler, search-based approach with special hardware and software proved vastly more effective, these human-knowledge-based chess researchers were not good losers. They said that ``brute force" search may have won this time, but it was not a general strategy, and anyway it was not how people played chess. These researchers wanted methods based on human input to win and were disappointed when they did not.

A similar pattern of research progress was seen in computer Go, only delayed by a further 20 years. Enormous initial efforts went into avoiding search by taking advantage of human knowledge, or of the special features of the game, but all those efforts proved irrelevant, or worse, once search was applied effectively at scale. Also important was the use of learning by self play to learn a value function (as it was in many other games and even in chess, although learning did not play a big role in the 1997 program that first beat a world champion). Learning by self play, and learning in general, is like search in that it enables massive computation to be brought to bear. Search and learning are the two most important classes of techniques for utilizing massive amounts of computation in AI research. In computer Go, as in computer chess, researchers' initial effort was directed towards utilizing human understanding (so that less search was needed) and only much later was much greater success had by embracing search and learning.

In speech recognition, there was an early competition, sponsored by DARPA, in the 1970s. Entrants included a host of special methods that took advantage of human knowledge---knowledge of words, of phonemes, of the human vocal tract, etc. On the other side were newer methods that were more statistical in nature and did much more computation, based on hidden Markov models (HMMs). Again, the statistical methods won out over the human-knowledge-based methods. This led to a major change in all of natural language processing, gradually over decades, where statistics and computation came to dominate the field. The recent rise of deep learning in speech recognition is the most recent step in this consistent direction. Deep learning methods rely even less on human knowledge, and use even more computation, together with learning on huge training sets, to produce dramatically better speech recognition systems. As in the games, researchers always tried to make systems that worked the way the researchers thought their own minds worked---they tried to put that knowledge in their systems---but it proved ultimately counterproductive, and a colossal waste of researcher's time, when, through Moore's law, massive computation became available and a means was found to put it to good use.

In computer vision, there has been a similar pattern. Early methods conceived of vision as searching for edges, or generalized cylinders, or in terms of SIFT features. But today all this is discarded. Modern deep-learning neural networks use only the notions of convolution and certain kinds of invariances, and perform much better.

This is a big lesson. As a field, we still have not thoroughly learned it, as we are continuing to make the same kind of mistakes. To see this, and to effectively resist it, we have to understand the appeal of these mistakes. We have to learn the bitter lesson that building in how we think we think does not work in the long run. The bitter lesson is based on the historical observations that 1) AI researchers have often tried to build knowledge into their agents, 2) this always helps in the short term, and is personally satisfying to the researcher, but 3) in the long run it plateaus and even inhibits further progress, and 4) breakthrough progress eventually arrives by an opposing approach based on scaling computation by search and learning. The eventual success is tinged with bitterness, and often incompletely digested, because it is success over a favored, human-centric approach.

One thing that should be learned from the bitter lesson is the great power of general purpose methods, of methods that continue to scale with increased computation even as the available computation becomes very great. The two methods that seem to scale arbitrarily in this way are search and learning.

The second general point to be learned from the bitter lesson is that the actual contents of minds are tremendously, irredeemably complex; we should stop trying to find simple ways to think about the contents of minds, such as simple ways to think about space, objects, multiple agents, or symmetries. All these are part of the arbitrary, intrinsically-complex, outside world. They are not what should be built in, as their complexity is endless; instead we should build in only the meta-methods that can find and capture this arbitrary complexity. Essential to these methods is that they can find good approximations, but the search for them should be by our methods, not by us. We want AI agents that can discover like we can, not which contain what we have discovered. Building in our discoveries only makes it harder to see how the discovering process can be done.


---------

<!-- 引入不蒜子统计脚本 -->
<script async src="//busuanzi.ibruce.info/busuanzi/2.3/busuanzi.pure.mini.js"></script>

<!-- 显示当前页面的访问量（即本文的阅读量） -->
<p>本文访问量：<span id="busuanzi_value_page_pv"></span> 次</p>

<!-- 可选：显示整个网站的总访问量 -->
<p>网站总访问量：<span id="busuanzi_value_site_pv"></span> 次</p>

