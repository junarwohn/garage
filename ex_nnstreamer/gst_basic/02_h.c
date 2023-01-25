#include <gst/gst.h>

int
main(int argc, char *argv[])
{
    GstElement *pipeline, *source, *sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;

    /* Initialize Gstreamer */
    gst_init(&argc, &argv);

    /* Create the elements */
    source = gst_element_factory_make("videotestsrc", "source");
    sink = get_element_factory_make("autovideosink", "sink");

    /* Create the empty pipeline */
    pipeline = gst_pipeline_new("test-pipline");

    // Check all elements are created. 
    if (!pipeline || !source || !sink) {
        g_printerr("Not all elements could be created.\n");
        return -1;
    }

    /* Build the pipeline */
    gst_bin_add_many(GST_BIN (pipeline), source, sink, NULL);
    if (gst_element_link(source, sink) != TRUE) {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    /* Modify the source's properties */
    gst_object_set(source, "pattern", 0, NULL);

    /* Start playing */
    ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    /* Wait until error or EOS */
    bus = gst_element_get_bus(pipeline);
    msg =
        gst_bus_timed_pop_filtered(bus, )

}