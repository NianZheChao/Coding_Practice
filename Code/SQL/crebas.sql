/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2012                    */
/* Created on:     2020/11/4 10:47:07                           */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('made') and o.name = 'FK_MADE_MADE_M')
alter table made
   drop constraint FK_MADE_MADE_M
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('made') and o.name = 'FK_MADE_MADE2_G')
alter table made
   drop constraint FK_MADE_MADE2_G
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('sell') and o.name = 'FK_SELL_SELL_S')
alter table sell
   drop constraint FK_SELL_SELL_S
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('sell') and o.name = 'FK_SELL_SELL2_G')
alter table sell
   drop constraint FK_SELL_SELL2_G
go

if exists (select 1
            from  sysobjects
           where  id = object_id('G')
            and   type = 'U')
   drop table G
go

if exists (select 1
            from  sysobjects
           where  id = object_id('M')
            and   type = 'U')
   drop table M
go

if exists (select 1
            from  sysobjects
           where  id = object_id('S')
            and   type = 'U')
   drop table S
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('made')
            and   name  = 'made2_FK'
            and   indid > 0
            and   indid < 255)
   drop index made.made2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('made')
            and   name  = 'made_FK'
            and   indid > 0
            and   indid < 255)
   drop index made.made_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('made')
            and   type = 'U')
   drop table made
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('sell')
            and   name  = 'sell2_FK'
            and   indid > 0
            and   indid < 255)
   drop index sell.sell2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('sell')
            and   name  = 'sell_FK'
            and   indid > 0
            and   indid < 255)
   drop index sell.sell_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('sell')
            and   type = 'U')
   drop table sell
go

/*==============================================================*/
/* Table: G                                                     */
/*==============================================================*/
create table G (
   Gno                  char(15)             not null,
   Gname                char(15)             null,
   Gprice               double precision     null,
   constraint PK_G primary key nonclustered (Gno)
)
go

/*==============================================================*/
/* Table: M                                                     */
/*==============================================================*/
create table M (
   Mno                  char(15)             not null,
   Mname                char(15)             null,
   Mtel                 char(15)             null,
   constraint PK_M primary key nonclustered (Mno)
)
go

/*==============================================================*/
/* Table: S                                                     */
/*==============================================================*/
create table S (
   Sno                  char(15)             not null,
   Sname                char(15)             null,
   Saddr                char(15)             null,
   constraint PK_S primary key nonclustered (Sno)
)
go

/*==============================================================*/
/* Table: made                                                  */
/*==============================================================*/
create table made (
   Mno                  char(15)             not null,
   Gno                  char(15)             not null,
   constraint PK_MADE primary key (Mno, Gno)
)
go

/*==============================================================*/
/* Index: made_FK                                               */
/*==============================================================*/
create index made_FK on made (
Mno ASC
)
go

/*==============================================================*/
/* Index: made2_FK                                              */
/*==============================================================*/
create index made2_FK on made (
Gno ASC
)
go

/*==============================================================*/
/* Table: sell                                                  */
/*==============================================================*/
create table sell (
   Sno                  char(15)             not null,
   Gno                  char(15)             not null,
   num                  int                  null,
   constraint PK_SELL primary key (Sno, Gno)
)
go

/*==============================================================*/
/* Index: sell_FK                                               */
/*==============================================================*/
create index sell_FK on sell (
Sno ASC
)
go

/*==============================================================*/
/* Index: sell2_FK                                              */
/*==============================================================*/
create index sell2_FK on sell (
Gno ASC
)
go

alter table made
   add constraint FK_MADE_MADE_M foreign key (Mno)
      references M (Mno)
go

alter table made
   add constraint FK_MADE_MADE2_G foreign key (Gno)
      references G (Gno)
go

alter table sell
   add constraint FK_SELL_SELL_S foreign key (Sno)
      references S (Sno)
go

alter table sell
   add constraint FK_SELL_SELL2_G foreign key (Gno)
      references G (Gno)
go
