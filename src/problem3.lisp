;; yeah whine about internal state but this is far more efficient
(defvar *primes-list* '(2 3))

(defun prime-p (n)
  (dolist (p *primes-list*)
    (if (= n p)
	t)
    (if (or
	 nil
	 (zerop (mod n p)))
	nil))

  (setf *primes-list* (append *primes-list* (list n)))
  t)

