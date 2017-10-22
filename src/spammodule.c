#include <Python.h>


static PyObject *SpamError;


static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    // sts = system(command);
    // if (sts < 0) {
    //     PyErr_SetString(SpamError, "System command failed");
    //     return NULL;
    // }
    // return PyLong_FromLong(sts);
    printf("Hello %s!\n", name);
    return Py_RETURN_NONE
}


static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


// This should be the only non-static item defined in the module file:
PyMODINIT_FUNC
PyInit_spam(void)
{
    PyObject *m;

    m = PyModule_Create(&spammodule);
    if (m == NULL)
        return NULL;

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
    return m;
}
