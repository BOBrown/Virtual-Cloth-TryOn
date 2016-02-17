﻿================================================================================
    MICROSOFT 基础类库 : Virtual-Cloth-TryOn 项目概述
===============================================================================

应用程序向导已为您创建了此 Virtual-Cloth-TryOn 应用程序。此应用程序不仅演示 Microsoft 基础类的基本使用方法，还可作为您编写应用程序的起点。

本文件概要介绍组成 Virtual-Cloth-TryOn 应用程序的每个文件的内容。

Virtual-Cloth-TryOn.vcxproj
    这是使用应用程序向导生成的 VC++ 项目的主项目文件，其中包含生成该文件的 Visual C++ 的版本信息，以及有关使用应用程序向导选择的平台、配置和项目功能的信息。

Virtual-Cloth-TryOn.vcxproj.filters
    这是使用“应用程序向导”生成的 VC++ 项目筛选器文件。它包含有关项目文件与筛选器之间的关联信息。在 IDE 中，通过这种关联，在特定节点下以分组形式显示具有相似扩展名的文件。例如，“.cpp”文件与“源文件”筛选器关联。

Virtual-Cloth-TryOn.h
    这是应用程序的主头文件。
    其中包括其他项目特定的标头（包括 Resource.h），并声明 CVirtualClothTryOnApp 应用程序类。

Virtual-Cloth-TryOn.cpp
    这是包含应用程序类 CVirtualClothTryOnApp 的主应用程序源文件。

Virtual-Cloth-TryOn.rc
    这是程序使用的所有 Microsoft Windows 资源的列表。它包括 RES 子目录中存储的图标、位图和光标。此文件可以直接在 Microsoft Visual C++ 中进行编辑。项目资源包含在 2052 中。

res\Virtual-Cloth-TryOn.ico
    这是用作应用程序图标的图标文件。此图标包括在主资源文件 Virtual-Cloth-TryOn.rc 中。

res\VirtualClothTryOn.rc2
    此文件包含不在 Microsoft Visual C++ 中进行编辑的资源。您应该将不可由资源编辑器编辑的所有资源放在此文件中。

/////////////////////////////////////////////////////////////////////////////

对于主框架窗口：
    该项目包含一个标准的 MFC 接口。

MainFrm.h, MainFrm.cpp
    这些文件中包含框架类 CMainFrame，该类派生自
    CFrameWnd 并控制所有 SDI 框架功能。

res\Toolbar.bmp
    此位图文件用于为工具栏创建平铺图像。
    初始工具栏和状态栏在 CMainFrame 类中构造。使用资源编辑器编辑此工具栏位图，并更新 Virtual-Cloth-TryOn.rc 中的 IDR_MAINFRAME TOOLBAR 数组以添加工具栏按钮。
/////////////////////////////////////////////////////////////////////////////

应用程序向导创建一种文档类型和一个视图：

Virtual-Cloth-TryOnDoc.h、Virtual-Cloth-TryOnDoc.cpp - 文档
    这些文件包含 CVirtualClothTryOnDoc 类。编辑这些文件以添加特殊文档数据并实现文件保存和加载（通过 CVirtualClothTryOnDoc::Serialize）。

Virtual-Cloth-TryOnView.h、Virtual-Cloth-TryOnView.cpp - 文档视图
    这些文件包含 CVirtualClothTryOnView 类。
    CVirtualClothTryOnView 对象用于查看 CVirtualClothTryOnDoc 对象。




/////////////////////////////////////////////////////////////////////////////

其他功能：

ActiveX 控件
    该应用程序包含对使用 ActiveX 控件的支持。

打印和打印预览支持
    应用程序向导通过从 MFC 库调用 CView 类中的成员函数生成代码，来处理打印、打印设置和打印预览命令。

/////////////////////////////////////////////////////////////////////////////

其他标准文件:

StdAfx.h, StdAfx.cpp
    这些文件用于生成名为 Virtual-Cloth-TryOn.pch 的预编译头 (PCH) 文件和名为 StdAfx.obj 的预编译类型文件。

Resource.h
    这是标准头文件，可用于定义新的资源 ID。Microsoft Visual C++ 将读取并更新此文件。

Virtual-Cloth-TryOn.manifest
	Windows XP 使用应用程序清单文件来描述特定版本的并行程序集的应用程序依赖项。加载程序使用这些信息来从程序集缓存中加载相应的程序集，并保护其不被应用程序访问。应用程序清单可能会包含在内，以作为与应用程序可执行文件安装在同一文件夹中的外部 .manifest 文件进行重新分发，它还可能以资源的形式包含在可执行文件中。
/////////////////////////////////////////////////////////////////////////////

其他注释:

应用程序向导使用“TODO:”来指示应添加或自定义的源代码部分。

如果应用程序使用共享 DLL 中的 MFC，您将需要重新分发 MFC DLL。如果应用程序所使用的语言与操作系统的区域设置不同，则还需要重新分发相应的本地化资源 mfc110XXX.DLL。
有关上述话题的更多信息，请参见 MSDN 文档中有关重新分发 Visual C++ 应用程序的部分。

/////////////////////////////////////////////////////////////////////////////
