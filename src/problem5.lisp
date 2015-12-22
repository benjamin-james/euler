
(defun is-divisible-by-all (number limit)
  (do ((i 2 (1+ i)))
      ((>= i limit) t)
    (if (not (zerop (mod number i)))
	(return nil))))

(defun problem5 (&optional (limit 20))
  (do ((num limit (incf num limit)))
      ((is-divisible-by-all num limit)
       (format t "The smallest number divisible to all numbers up to ~d is ~d~%" limit num))))

