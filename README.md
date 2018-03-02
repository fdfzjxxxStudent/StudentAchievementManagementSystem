# StudentAchievementManagementSystem
<h3>这是一个本地管理学生成绩的系统，使用加密过的文件储存信息。</h3>
<h3>另外，Windows版本同时支持管理和查询。</h3> 
<h3>Windows版本学生模式登陆用户名“Student”或“学生”，免密码。</h3>
<h4>作者：<a href="https://github.com/XiyuWang2006/">XiyuWang2006</a></h4>

<hr></hr>
<h3>功能：</h3>
<h3>1.（管理员账户）两种输入信息方式，支持更改信息、删除信息</h3>
<h3>    (1)分散输入信息（考试不同，班级不同）</h3>
<h3>    (2)集体输入信息（考试相同，班级相同，要求已创建班级，可免去输入学生姓名和学号，考试名称只需输入一次）</h3>
<h3>2.（管理员账户+学生账户）五种查询方式</h3>
<h3>    (1)查看所有信息</h3>
<h3>    (2)查看单个学生的所有信息</h3>
<h3>    (3)查看特定分数线内所有学生的信息</h3>
<h3>    (4)查看特定考试内所有学生的信息</h3>
<h3>    (5)查看现有班级内所有学生的信息</h3>
<h3>3.（管理员账户）数据自动查错</h3>
<h3>4.（Windows版本专属）可以使用学生账户登录，要求输入学生姓名</h3>
<h3>5.（Windows版本专属）为了用户安全起见，在更改用户密码或班级名称、密码时必须以管理员账户验证（修复学生账户登陆也可以成功通过验证）</h3>
<hr />
<h2>最新推出功能：数据查错（通用版本）</h2>
<h3>功能：检查成绩是否均为数字或小数</h3>
<h3>更新前16.9.17版本：成绩含有字母或符号（浮点除外）将会导致成绩为零分</h3>
<h3>更新后16.9.18版本：成绩含有字母或符号（浮点除外）将会提示用户重新输入数据</h3>
<hr />
<p><a href="https://github.com/XiyuWang2006/StudentAchievementManagementSystem/tree/master/WindowsEdition/">Windows简体中文版</a>
 <a href="https://github.com/XiyuWang2006/StudentAchievementManagementSystem/tree/master/LinuxEdition/">Linux简体中文版</a></p>
 <hr></hr>
<h5>注意：请务必使用g++编译，其它编译器可能会报错，也可能运行时出错！</h5>
<h6>P.S.:StudentAchievementManagementSystem简称SAMS，zh-cn代表简体中文</h6>
