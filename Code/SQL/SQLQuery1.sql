CREATE DATABASE EXAM

INSERT INTO G
(Gno, Gname, Gprice)
VALUES
('G0001', '�������̲�', 20)

INSERT INTO G
(Gno, Gname, Gprice)
VALUES
('G0002', 'ȸ������', 25)

INSERT INTO G
(Gno, Gname, Gprice)
VALUES
('G0003', '����', 5)

INSERT INTO M
(Mno, Mname, Mtel)
VALUES
('M0001', '��������', '00001')

INSERT INTO M
(Mno, Mname, Mtel)
VALUES
('M0002', '�����ִ�', '00002')

INSERT INTO M
(Mno, Mname, Mtel)
VALUES
('M0003', '�Ϻ�����', '00003')

INSERT INTO M
(Mno, Mname, Mtel)
VALUES
('M0004', '��Դ��˾', '00004')

INSERT INTO S
(Sno, Sname, Saddr)
VALUES
('S0001', 'Tom', 'chongqing')

INSERT INTO S
(Sno, Sname, Saddr)
VALUES
('S0002', 'Jerry', 'beijing')

INSERT INTO S
(Sno, Sname, Saddr)
VALUES
('S0003', '����', 'shanghai')

INSERT INTO made
(Mno, Gno)
VALUES
('M0004','G0001')

INSERT INTO made
(Mno, Gno)
VALUES
('M0004','G0002')

INSERT INTO made
(Mno, Gno)
VALUES
('M0003','G0003')

INSERT INTO sell
(Sno, Gno, num)
VALUES
('S0003', 'G0002', 5)

INSERT INTO sell
(Sno, Gno, num)
VALUES
('S0003', 'G0001', 3)

INSERT INTO sell
(Sno, Gno, num)
VALUES
('S0001', 'G0003', 10)

CREATE VIEW Liuchen_goods
AS
SELECT G.Gname
FROM S JOIN sell
ON S.Sno = sell.Sno
JOIN G
ON G.Gno = sell.Gno
WHERE S.Sname = '����'

select * from Liuchen_goods

SELECT G.Gname, sell.num 
FROM G JOIN sell
ON G.GNO = sell.Gno

SELECT M.Mname
FROM M JOIN made
ON M.Mno = made.Mno
WHERE MADE.Gno = 'G0001'
OR MADE.Gno = 'G0002'

UPDATE G
SET G.Gprice = G.Gprice * 1.03
WHERE Gno IN(
SELECT G.Gno 
FROM G JOIN made
ON G.Gno = made.Gno
JOIN M
ON M.Mno = made.Mno
WHERE M.Mname = '��Դ��˾'
)

select * from G

DELETE 
FROM sell
WHERE Sno IN(
SELECT sell.Sno
FROM sell JOIN S
ON sell.Sno = S.Sno
WHERE S.Sname = '����'
)

SELECT * FROM sell