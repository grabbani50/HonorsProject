USE [master]
GO

/****** Object:  Table [dbo].[scholarships]    Script Date: 5/11/2021 2:42:31 AM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[scholarships](
	[id] [int] NULL,
	[name] [varchar](1000) NULL,
	[duedate] [varchar](100) NULL,
	[amount] [float] NULL,
	[qualification] [varchar](1000) NULL,
	[gpa] [float] NULL,
	[applicationlink] [varchar](1000) NULL
) ON [PRIMARY]
GO

