#ifndef	_ASN1_COMPILER_MISC_H_
#define	_ASN1_COMPILER_MISC_H_

/*
 * Make the target language identifier out of one or more names.
 * The function will concatenate the names and replace unsafe characters
 * with safe ones.
 */
enum ami_flags_e {
  AMI_MASK_ONLY_SPACES	= 1,	/* Mask only spaces, everything else's safe */
  AMI_CHECK_RESERVED	= 2,	/* Check against reserved keywords */
};
char *asn1c_make_identifier(enum ami_flags_e, char *arg1, ...);

/*
 * Return the type name of the specified expression.
 */
enum tnfmt {
	TNF_NORCHECK	= 0x00,
	TNF_CHECK	= 0x01,
	TNF_UNMODIFIED	= 0x10,	/* Return unmodified type name */
	TNF_INCLUDE	= 0x20,	/* Format for #include <> */
	TNF_CTYPE	= 0x30,	/* Format as normal C-ish type (append "_t") */
	TNF_SAFE	= 0x40, /* Replace unsafe characters with _ */
	TNF_RSAFE	= 0x50,	/* Recursion-safe C type format */
};
char *asn1c_type_name(arg_t *arg, asn1p_expr_t *expr, enum tnfmt _format);

#endif	/* _ASN1_COMPILER_MISC_H_ */
