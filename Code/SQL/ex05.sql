USE SuperMarket
go
CREATE PROCEDURE PRO_AVG
@SUP_NAME CHAR(10)
AS
SELECT AVG(Saleprice) FROM Goods
JOIN Supplier
ON Supplier.SupplierNO = Goods.SupplierNO
WHERE SupplierName = @SUP_NAME 
Go

USE SuperMarket
GO
CREATE PROC COLLEGE_BUY
@COLLEGE CHAR(10)
AS
SELECT student.College, SUM(Salebill.Number) as sale_num, SUM(Goods.Number) as Good_num, max(Salebill.HappenTime)
FROM Goods JOIN Salebill
ON Goods.GoodsNO = Salebill.GoodsNO
JOIN student
ON student.SNO = Salebill.SNO
GROUP BY student.College
GO

USE SuperMarket
GO
CREATE PROC ADD_GOODS
AS
SELECT Number as less_Goods FROM Goods
WHERE Number < 10
BEGIN
WHILE (SELECT MIN(Number) FROM Goods) < 10
BEGIN
SELECT Number = Number + 1
FROM Goods WHERE Number < 10
END
end

EXEC ADD_GOODS

CREATE FUNCTION MAX_AGE(@COL CHAR(10))
RETURNS INT
AS
BEGIN
	DECLARE @YEARS INT
	SELECT @YEARS = MAX(2020-BirthYear) from student
	WHERE College = @COL
	--PRINT @YEARS
	RETURN @YEARS
END
SELECT * FROM MAX_AGE('CS')

CREATE FUNCTION TIME_SALE(@BEGIN_DATE DATE,@END_DATE DATE)
RETURNS INT
AS
BEGIN
	DECLARE @NUM INT
	SELECT @NUM = SUM(Number) FROM SaleBill
	WHERE HappenTime < @END_DATE
	AND HappenTime > @BEGIN_DATE
	RETURN @NUM
END

CREATE FUNCTION SUP_INFO(@ADDR_SUP CHAR(10))
RETURNS @INFO TABLE
	(SUP_NO CHAR(10),
	SUP_NAME CHAR(10),
	SUP_NUM CHAR(15),
	GOOD_NO CHAR(10),
	GOOD_NAME CHAR(10),
	GOOD_NUM INT
	)
AS BEGIN
	INSERT INTO @INFO
	SELECT Supplier.SupplierNO, Supplier.SupplierName, Supplier.Number, Goods.GoodsNO, Goods.GoodsName, Goods.Number
	FROM Supplier JOIN GOODS
	ON Goods.SupplierNO = Supplier.SupplierNO
	WHERE Supplier.Address = @ADDR_SUP
	RETURN
end
DROP FUNCTION SUP_INFO

GO
SELECT * FROM SUP_INFO('¹ã¶«·ðÉ½')

CREATE TRIGGER DEL_SUP
ON Supplier
AFTER DELETE
AS
DELETE FROM Goods
WHERE SupplierNO = (SELECT SupplierNO FROM deleted)
GO

CREATE TRIGGER INSERT_SALE
ON SaleBill
AFTER INSERT
AS
declare @add_num INT
select @ADD_NUM = number FROM inserted
UPDATE Goods
SET Number = Number - @add_num
GO