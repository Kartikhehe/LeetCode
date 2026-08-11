# Write your MySQL query statement below
WITH totalpricetable as (
    SELECT us.product_id, us.purchase_date, us.units, us.units * (CASE WHEN Prices.product_id = us.product_id AND us.purchase_date BETWEEN Prices.start_date AND Prices.end_date THEN Prices.price ELSE 0 END ) as total_price
    FROM UnitsSold us
    LEFT JOIN Prices
    ON Prices.product_id = us.product_id AND us.purchase_date BETWEEN Prices.start_date AND Prices.end_date
)

SELECT Prices.product_id, ROUND(IFNULL(SUM(total_price) / SUM(units), 0), 2) AS average_price
FROM Prices
LEFT JOIN totalpricetable
ON totalpricetable.product_id = Prices.product_id
GROUP BY product_id;