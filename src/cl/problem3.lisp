
(defun prime-p (n &optional (d 2))
  (or (>= d n)
      (and (/= (rem n d) 0)
	   (prime-p n (+ d 1)))))

(defun max-prime-factor (n)
  (do ((i (floor (sqrt n)) (1- i)))
      ((< i 4) i)
    (if (and (= 0 (mod n i))
	     (prime-p i))
	(return-from max-prime-factor i))))

(defun problem3 (&optional (number 600851475143))
  (format t "The largest prime factor of ~d is ~d~%" number (max-prime-factor number)))
