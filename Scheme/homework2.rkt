#lang racket

(define image1
 (list
	    (list 0 1) (list 0 2)	     (list 0 4)
	    (list 1 1) (list 1 2)	     (list 1 4)	           (list 1 6)
 (list 2 0) (list 2 1) (list 2 2)	     (list 2 4) 	   (list 2 6)
	   				     (list 3 4) (list 3 5) (list 3 6) 
	    (list 4 1)
	    (list 5 1) (list 5 2) (list 5 3) (list 5 4) (list 5 5)
	    (list 6 1) (list 6 2) (list 6 3)
))

(define (copy lst)
	(cond ((empty? lst) '())
	   	(else (cons (car lst) (copy(cdr lst) )))))

(define editableimage (copy image1))

;editableimage

;(define (connectedComponents lst image1)
;	(cond ((empty? image1) '())
;		((member? (car image1) lst) (connectedComponents lst (cdr image1)))
;		(#f (cons lst (car image1))
;			(connectedComponents lst (cdr image1)))))  
;

(define isMember 
	(lambda (xs1 xss2)
	(cond
		((null? xss2) #f)
		((equal? xs1 (car xss2)) #t)
		((not (equal? xs1 (car xss2)))
			(isMember xs1 (cdr xss2))))))


;(isMember '(6 1) '((5 1)(6 1)(7 1)))


(define foo "ADJACENCY PRINT BELOW:")

foo

;(define xs (car image1))
;(define testlist (list (+ 1 (car xs)) (cadr xs)))
;xs
;testlist 

(define adjacency
     (lambda (xs image1)
	(define help "help")
	(display help)
	(newline)
	;Conds below search for vertical adjacents
	(cond
	  ;if image1 is null, then return the null list and break 
	  ;out of the cond block
	  ((null? image1) '()) 
	  ((isMember (list (+ 1 (car xs)) (car xs)) image1)
	     (define xsn
		(list (+ 1 (car xs)) (car xs)))
		  (display xsn
		  ;(values xsn
		  	  (adjacency 
			     xsn
		             (cdr image1)))))))


(define bar (adjacency (list 0 4) (cdr image1)))
(list bar)
(newline)






			
